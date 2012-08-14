/****************************************************************************
 * This file is part of System Preferences.
 *
 * Copyright (c) 2011-2012 Pier Luigi Fiorini
 *
 * Author(s):
 *    Pier Luigi Fiorini <pierluigi.fiorini@gmail.com>
 *
 * $BEGIN_LICENSE:GPL$
 *
 * System Preferences is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * System Preferences is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with System Preferences.  If not, see <http://www.gnu.org/licenses/>.
 *
 * $END_LICENSE$
 ***************************************************************************/

#include <QDebug>
#include <QIcon>

#include <VDeviceNotifier>
#include <VAudioInterface>

#include "soundcardmodel.h"

SoundCardModel::SoundCardModel(QObject *parent) :
    QAbstractListModel(parent)
{
    m_notifier = VDeviceNotifier::instance();
    m_list = VDevice::listFromType(VDeviceInterface::AudioInterface);
}

QVariant SoundCardModel::data(const QModelIndex &index, int role) const
{
    // Sanity check
    if (!index.isValid())
        return QVariant();

    // Check if role is supported
    if (role != Qt::DisplayRole && role != Qt::DecorationRole)
        return QVariant();

    VDevice device = m_list.at(index.row());
    VAudioInterface *audio = device.as<VAudioInterface>();

    if (audio->deviceType() == VAudioInterface::AudioOutput) {
        qDebug() << device.udi() << device.product() << device.parentUdi();
        switch (role) {
            case Qt::DisplayRole:
                return audio->name();
            case Qt::DecorationRole:
                switch (audio->soundcardType()) {
                    case VAudioInterface::Headset:
                        return QIcon::fromTheme("audio-headset");
                    default:
                        return QIcon::fromTheme("audio-card");
                }
        }
    }

    return QVariant();
}

int SoundCardModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_list.size();
}

#include "moc_soundcardmodel.cpp"