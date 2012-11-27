# Activates Windows 8 Applications

This is a simple command-line app and/or Node.js library that activates a Windows 8 application. It takes as its sole
parameter an “application user model ID,” which is a somewhat-cryptic string that identifies apps throughout Windows 8.

You can use it from JavaScript like so:

```js
var activate = require("winningjs-activator");

activate("Microsoft.BingWeather_8wekyb3d8bbwe!App", function (err) {
    // If `err` doesn't exist, your app is activated and showing on the user's screen!
    // Otherwise it contains an informative error message with an HRESULT.
});
```

or if you install it globally, you can use it from the command line:

```
C:\> WinningJS-activator Microsoft.BingWeather_8wekyb3d8bbwe!App
```

For more information on how this is accomplished, check out this [MSDN article][].

## Installation

Although you can compile the source directly by navigating to the `src/` directory, I've made it easy to install this
tool through [npm][], the Node.js package manager. You'll need to have Visual Studio 2012 installed (the
[free edition][] works fine), but if you do, then just type

```
C:\> npm install winningjs-activator
```

and it will download the source and compile it into something ready for you to use. As mentioned above, if you want it
as a general command-line tool, just add the `-g` flag and it will be placed in your PATH.

[MSDN article]: http://blogs.msdn.com/b/windowsappdev/archive/2012/09/04/automating-the-testing-of-windows-8-apps.aspx
[npm]: https://npmjs.org/
[free edition]: http://www.microsoft.com/visualstudio/eng/products/visual-studio-express-for-windows-8
