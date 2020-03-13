
## 可以使用的IDE

- Qt Creator 
- CLion 
- Visual Studio 2017
- Visual Studio 2019 

## Qt Creator

> 如果要使用Qt Creator 编译，必须安装Visual Studio 2017

## Clion

> 只能使用Visual Studio 2017 的编译器

生产完成后使用

    namke 

编译安装
    





### 环境变量添加

    QT5QMLMODELS_DIR=D:/Local/Qt/5.14.1/msvc2017_64/lib/cmakeQt5QmlModels;
    QT5QML_DIR=D:/Local/Qt/5.14.1/msvc2017_64/lib/cmake/Qt5Qml;
    QT5QUICK_DIR=D:/Local/Qt/5.14.1/msvc2017_64/lib/cmake/Qt5Quick;
    QT5_DIR=D:/Local/Qt/5.14.1/msvc2017_64/lib/cmake/Qt5;
    Qt5Core_DIR=D:/Local/Qt/5.14.1/msvc2017_64/lib/cmake/Qt5Core;
    Qt5Gui_DIR=D:/Local/Qt/5.14.1/msvc2017_64/lib/cmake/Qt5Gui;
    Qt5Network_DIR=D:/Local/Qt/5.14.1/msvc2017_64/lib/cmake/Qt5Network

## Visual Studio 
###  CMakeSettings.json 配置如下

1. 输出路径改为自己的
2. Qt 配置的路径改为自己的



    {
      "configurations": [
        {
          "name": "x64-Release",
          "generator": "Visual Studio 16 2019 Win64",
          "configurationType": "Release",
          "inheritEnvironments": [
            "msvc_x64_x64"
          ],
          "buildRoot": "${env.USERPROFILE}\\CMakeBuilds\\${workspaceHash}\\build\\${name}",
          "installRoot": "D:/Local/libs",
          "cmakeCommandArgs": "",
          "variables": [
            {
              "name": "Qt5Core_DIR",
              "value": "D:/Local/Qt/5.14.1/msvc2017_64/lib/cmake/Qt5Core",
              "type": "FILEPATH"
            },
            {
              "name": "Qt5Gui_DIR",
              "value": "D:/Local/Qt/5.14.1/msvc2017_64/lib/cmake/Qt5Gui",
              "type": "FILEPATH"
    
            },
            {
              "name": " Qt5Network_DIR",
              "value": "D:/Local/Qt/5.14.1/msvc2017_64/lib/cmake/Qt5Network",
              "type": "FILEPATH"
    
            },
            {
              "name": " Qt5QmlModels_DIR",
              "value": "D:/Local/Qt/5.14.1/msvc2017_64/lib/cmakeQt5QmlModels",
              "type": "FILEPATH"
    
            },
            {
              "name": " Qt5Qml_DIR",
              "value": "D:/Qt/Qt5.14.1/5.14.1/msvc2017_64/lib/cmake/Qt5Qml",
              "type": "FILEPATH"
    
            },
            {
              "name": " Qt5Quick_DIR",
              "value": "D:/Qt/Qt5.14.1/5.14.1/msvc2017_64/lib/cmake/Qt5Quick",
              "type": "FILEPATH"
    
            },
            {
              "name": " Qt5_DIR",
              "value": "D:/Local/Qt/5.14.1/msvc2017_64/lib/cmake/Qt5",
              "type": "FILEPATH"
            }
          ]
        }
      ]
    }