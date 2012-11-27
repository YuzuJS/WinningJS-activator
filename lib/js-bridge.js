"use strict";

var path = require("path");
var childProcess = require("child_process");

var packageInfo = require("../package.json");
var binPath = path.resolve(__dirname, "..", packageInfo.bin["WinningJS-activator"]);

module.exports = function (appId, cb) {
    if (typeof cb !== "function") {
        cb = function () {};
    }

    childProcess.execFile(binPath, [appId], function (err, stderr) {
        if (err) {
            cb(new Error(stderr.toString() + " (HRESULT: " + err.code + ")"));
            return;
        }

        cb();
    });
};
