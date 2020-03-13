#pragma once

#ifndef IAPPPLUGININTERFACE_H
#define IAPPPLUGININTERFACE_H

#include <QDate>
#include <QObject>
#include <QString>
#include <QtPlugin>
#include <bdlbsc/plugin/supper/PluginMetaData.h>

namespace bdlbsc
{
    // 插件接口
    class IAppPluginInterface : public QObject
    {
        Q_OBJECT
    public:
        virtual ~IAppPluginInterface() {}

        // 接收消息
        virtual void receive_message(PluginMetaData *) = 0;

        // 发送消息
        virtual void send_message(PluginMetaData *) = 0;

        // 加载插件
        virtual void loader() = 0;
    };

} // namespace bdlbsc
#endif // IAPPPLUGININTERFACE_H

// app plugin supper
#define BDLBSC_APP_PLUGIN_INTERFACE_IID "bdlbsc.com-project.Qt.app.plugin.interface"

Q_DECLARE_INTERFACE(bdlbsc::IAppPluginInterface, BDLBSC_APP_PLUGIN_INTERFACE_IID)
