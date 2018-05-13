# WicketWallpaperDaemon

This is a simple C++ HTTP application which needs the address of a picture in the web as an input, downloads it to an also given file and sets it as the wallpaper. Then it steadily watches this picture, and if it finds a new version of it, it automatically 
downloads it and updates the walpaper with its content.

Example: */path/to/WicketWallpaperDaemon.exe glockner.viewbito.com /current/p_01.jpg C:\Users\%USERNAME%\Wallpaper.jpg*
**Whereis**

/path/to/WicketWallpaperDaemon.exe*: where you have saved WicketWallpaperDeamon.exe to
*glockner.viewbito.com*: the DNS name of the server
*/current/p_01.jpg*: the location of the picture on the HTTP server
*C:\Users\%USERNAME%\Wallpaper.jpg*: where you want the picture to be saved to
