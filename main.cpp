#include <thread>
#include <string>
#include <iostream>
#include <fstream>
#include "boost/asio/ip/tcp.hpp"
#include <windows.h>
#include <chrono>
using namespace std;
using boost::asio::ip::tcp;

int main(int argc, char* argv[])
{
    if (argc != 4)
    {
        std::cerr << "Usage: Wallpaper <host> <hostfilelocation>" << std::endl;
        return 1;
    }
    ofstream wallpaper;
    string header;
    string methode = "HEAD";
    string lastetag = "";
    //string regkey = "L\"";
    //regkey.insert(3,1,argv[3])

    while (1)
    {
        bool breakagain = false;
        //cout << methode;
        tcp::iostream stream;

		stream.expires_from_now(chrono::seconds(60));
        stream.connect(argv[1], "http");
        stream << methode << " " << argv[2] << " HTTP/1.1\r\n";
        stream << "Host: " << argv[1] << "\r\n";
        stream << "Accept: */*\r\n";
        stream << "Connection: close\r\n\r\n";
        if (!stream)
        {
            cerr << "TCP Error" << endl;
            this_thread::sleep_for(chrono::seconds(1));
            continue;
        }
        stream.flush();
        int i = 1;
        while (std::getline(stream, header) && header != "\r")
        {
            if (header.find("200 OK") == string::npos && i == 1)
            {
                i = 0;
                break;
            }
            if (methode == "HEAD")
            {
                if (header.find("ETag") != string::npos)
                {
                    if (header != lastetag)
                    {
                        lastetag = header;
                        methode = "GET";
                        //cout << "Another ETAg";
                    }
                else {
                    cerr << "Same ETag" << endl;
                    this_thread::sleep_for(chrono::seconds(10));
                }
                    breakagain = true;
                        break;
                }

            }
            i ++;

        }
        if (i == 0)
        {
            cerr << "HTTP Error" << endl;
            this_thread::sleep_for(chrono::seconds(1));
            continue;
        }
        if (breakagain == true)
        {
            continue;
        }
        //cout << "HI";
        wallpaper.open(argv[3], ios::trunc | ios::binary);
        wallpaper << stream.rdbuf();
        wallpaper.close();
        if(SystemParametersInfoA(SPI_SETDESKWALLPAPER, NULL, argv[3], SPIF_SENDCHANGE) != true)
        {
            cerr << "Registry Error" << endl;
            this_thread::sleep_for(chrono::seconds(1));
            continue;
        }
        cerr << "Success" << endl;
        if (methode == "GET")
        {
            methode = "HEAD";
        }
    this_thread::sleep_for(chrono::seconds(10));
    }
}
