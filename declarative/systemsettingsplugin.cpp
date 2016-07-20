/****************************************************************************
 * This file is part of Hawaii.
 *
 * Copyright (C) 2016 Pier Luigi Fiorini
 *
 * Author(s):
 *    Pier Luigi Fiorini <pierluigi.fiorini@gmail.com>
 *
 * $BEGIN_LICENSE:LGPL2.1+$
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * $END_LICENSE$
 ***************************************************************************/

#include <QtQml/qqml.h>
#include <QtQml/QQmlExtensionPlugin>

#include "plugin.h"
#include "pluginsmodel.h"

class SystemSettingsPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")
public:
    void registerTypes(const char *uri);
};

void SystemSettingsPlugin::registerTypes(const char *uri)
{
    Q_ASSERT(QByteArray("Hawaii.SystemSettings") == QByteArray(uri));

    // @uri Hawaii.SystemSettings
    qmlRegisterType<Plugin>();
    qmlRegisterType<PluginsModel>(uri, 1, 0, "PluginsModel");
}

#include "systemsettingsplugin.moc"
