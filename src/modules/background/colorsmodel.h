/****************************************************************************
 * This file is part of Settings.
 *
 * Copyright (C) 2018 Pier Luigi Fiorini <pierluigi.fiorini@gmail.com>
 *
 * $BEGIN_LICENSE:GPL3+$
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
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

#ifndef COLORSMODEL_H
#define COLORSMODEL_H

#include <QtCore/QAbstractListModel>

class ColorsModelPrivate;

class ColorsModel : public QAbstractListModel
{
    Q_OBJECT
    Q_ENUMS(Roles)
public:
    enum Roles {
        ColorRole = Qt::UserRole + 1
    };

    explicit ColorsModel(QObject *parent = 0);

    QHash<int, QByteArray> roleNames() const;

    int rowCount(const QModelIndex &parent) const;

    QVariant data(const QModelIndex &index, int role) const;

    Q_INVOKABLE QColor get(int index) const;

public Q_SLOTS:
    void addCustomColor(const QColor &color);

    void clear();

private:
    Q_DECLARE_PRIVATE(ColorsModel)
    ColorsModelPrivate *const d_ptr;
};

#endif // COLORSMODEL_H
