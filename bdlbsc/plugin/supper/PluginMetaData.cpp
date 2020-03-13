//
// Created by 毛华伟 on 2020/1/3.
//

#include <bdlbsc/plugin/supper/PluginMetaData.h>

namespace bdlbsc
{
    PluginMetaData::PluginMetaData() {}

    QString *PluginMetaData::get_data() const
    {
        return data;
    }

    void PluginMetaData::set_data(QString *data)
    {
        PluginMetaData::data = data;
    }

    QObject *PluginMetaData::get_object() const
    {
        return object;
    }

    void PluginMetaData::set_object(QObject *object)
    {
        PluginMetaData::object = object;
    }
} // namespace bdlbsc
