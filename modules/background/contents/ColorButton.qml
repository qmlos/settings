/****************************************************************************
 * This file is part of Hawaii Shell.
 *
 * Copyright (C) 2014-2016 Pier Luigi Fiorini
 *
 * Author(s):
 *    Pier Luigi Fiorini <pierluigi.fiorini@gmail.com>
 *
 * $BEGIN_LICENSE:GPL2+$
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * $END_LICENSE$
 ***************************************************************************/

import QtQuick 2.0
import QtQuick.Dialogs 1.1
import Qt.labs.controls 1.0

Button {
    property alias color: dialog.color

    id: button
    onClicked: dialog.visible = true

    Rectangle {
        anchors {
            fill: parent
            margins: 11
        }
        color: button.color
    }

    ColorDialog {
        id: dialog
        modality: Qt.WindowModal
        title: qsTr("Choose a color")
        showAlphaChannel: false
    }
}
