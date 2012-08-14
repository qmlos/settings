/****************************************************************************
 * This file is part of Preferences.
 *
 * Copyright (c) 2012 Pier Luigi Fiorini
 *
 * Author(s):
 *    Pier Luigi Fiorini <pierluigi.fiorini@gmail.com>
 *
 * Preferences is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Preferences is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Preferences.  If not, see <http://www.gnu.org/licenses/>.
 ***************************************************************************/

#include "plugin.h"
#include "preflet.h"

MimeTypesPlugin::MimeTypesPlugin() :
    VPreferencesModulePlugin()
{
}

QString MimeTypesPlugin::name() const
{
    return tr("MIME Types");
}

QString MimeTypesPlugin::comment() const
{
    return tr("Configure the association between MIME types and programs.");
}

QString MimeTypesPlugin::iconName() const
{
    return "preferences-desktop-wallpaper";
}

QStringList MimeTypesPlugin::keywords() const
{
    return tr("mime;types;association;program").split(";");
}

VPreferencesModulePlugin::Category MimeTypesPlugin::category() const
{
    return VPreferencesModulePlugin::PersonalCategory;
}

int MimeTypesPlugin::weight() const
{
    return 50;
}

VPreferencesModule *MimeTypesPlugin::module() const
{
    return new Preflet();
}

Q_EXPORT_PLUGIN2(mimetypes, MimeTypesPlugin)

#include "moc_plugin.cpp"