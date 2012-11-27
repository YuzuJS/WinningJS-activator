# Activates Windows 8 Applications

This is the a simple command-line app that activates a Windows 8 application. It takes as its sole parameter an
“application user model ID,” which is a somewhat-cryptic string that identifies apps throughout Windows 8.

After installing, you can use it like so:

```
C:\> WinningJS-activator Microsoft.BingWeather_8wekyb3d8bbwe!App
```

For more information on how this is accomplished, check out this [MSDN article][].

## Installation

Although you can compile the source directly by navigating to the `src/` directory, I've made it easy to install this
tool through [npm][], the Node.js package manager. You'll need to have Visual Studio 2012 installed (the
[free edition][] works fine), but if you do, then just type

```
C:\> npm install -g WinningJS-activator
```

and it will download the source, compile it, and install an executable in your PATH.

## Future Work

It's likely I'll expand this in the near future to [extract][] the application user model ID from the AppX manifest,
so that you can just point the activator at your package name or package manifest or folder or something else easier to
find. That might necessitate moving to C# and P/Invoke since damn guys, this C++ shit is annoying.

More importantly, this will be a dependency of the forthcoming WinningJS-activate, which will allow you to activate
Windows 8 applications from Node.js.

[MSDN article]: http://blogs.msdn.com/b/windowsappdev/archive/2012/09/04/automating-the-testing-of-windows-8-apps.aspx
[extract]: http://msdn.microsoft.com/en-us/library/windows/desktop/hh446702%28v=vs.85%29.aspx
[npm]: https://npmjs.org/
[free edition]: http://www.microsoft.com/visualstudio/eng/products/visual-studio-express-for-windows-8
