## app 插件接口定义

文档在docs文件夹下



## manifest.json 配置插件信息


### 插件ID
id  类型 : QString
### 插件名称
name    类型 : QString 
### 插件作者
author  类型 : QString
### 插件发布时间
date    类型 : QString
### 插件版本名称
version_name    类型 : QString
### 插件版本号
version_code    类型 : int
### 插件简介
desc    类型 : QString
### 插件icon本地
icon_local  类型 : QString
### 插件icon原创地址
icon_remotely   类型 : QString
### 插件是否强制更新
force_update    类型 : QString
### 插件是否为独立窗口
independent_window  类型 : QString
### 插件main_qml
main_qml    类型 : QString

eg:

{
  "id": "baidu",
  "name": "百度搜索工具",
  "author": "毛华伟",
  "date": "2020/03/03",
  "version_name": "dev-laster",
  "version_code": "1",
  "desc": "中文检索引擎",
  "icon_local": "qrc:/images/image_baidu.png",
  "icon_remotely": "https://... 配置 cdn 地址",
  "force_update": "true",
  "independent_window": false,
  "main_qml": "qrc:/plugin/qml/web/baidu.qml"
}

