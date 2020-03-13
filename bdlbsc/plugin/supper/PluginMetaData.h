//
// Created by 毛华伟 on 2020/1/3.
//

#ifndef IAPPPLUGININTERFACE_PLUGINMETADATA_H
#define IAPPPLUGININTERFACE_PLUGINMETADATA_H

#include <QObject>
namespace bdlbsc
{
    class PluginMetaData : public QObject
    {
        Q_OBJECT
    private:
        QString *data;
        QObject *object;

    public:
        PluginMetaData();
        QString *get_data() const;
        void set_data(QString *data);
        QObject *get_object() const;
        void set_object(QObject *object);
    };
} // namespace bdlbsc

#endif //IAPPPLUGININTERFACE_PLUGINMETADATA_H
