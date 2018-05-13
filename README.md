# WicketWallpaperDaemon

This is a simple C++ Boost.Asio HTTP application which needs the address of a picture in the web as an input argument, downloads it to an also given file and sets it as the wallpaper. Now it will steadily watch this picture, and if the pictures gets updated on the server, it will automatically download it and update the wallpaper with its content.

**Example: *path\to\WicketWallpaperDaemon.exe example.com /path/to/picture/on/server.jpg path\to\picture\on\PC.jpg***

**Whereis:**
- *path\to\WicketWallpaperDaemon.exe*: where you have saved WicketWallpaperDeamon.exe to
- *example.com*: the DNS name of the server
- */path/to/picture/on/server.jpg*: the location of the picture on the HTTP server
- *path\to\picture\on\PC.jpg*: where you want the picture to be saved to
