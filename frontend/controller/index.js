/**
 * @description
 *  controller的初始化入口
 */

var path = require('path');
var glob = require('glob');

// 存放controller
var controllers = {};

// 查找Controller结尾的js文件
glob(
    '**/*Controller.js',
    {
        cwd: __dirname
    },
    function(er, files) {
        // 遍历找到的文件
        files.forEach(function(file) {
            var name = getName(file);

            controllers[name] = require(__dirname + '/' + file.replace('.js', ''));
        });
    }
);

/**
 * 根据controller的名称获取小写名称
 */
function getName(filename) {
    var name = path.basename(filename, '.js');
    name = name.replace('Controller', '');
    return name;
}

module.exports = controllers;
