/****************************************************************************
 * This file is part of Preferences.
 *
 * Copyright (c) 2011-2012 Pier Luigi Fiorini
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

#include <QtCore/qplugin.h>

#include <VSettings>

#include "preflet.h"
#include "ui_desktopscreensaverpreflet.h"
#include "backgroundcategoriesmodel.h"
#include "backgroundsmodel.h"
#include "backgrounditemdelegate.h"

Preflet::Preflet(QWidget *parent) :
    VPreferencesModule(parent),
    ui(new Ui::DesktopScreenSaverPreflet)
{
    ui->setupUi(this);

    ui->addButton->setIcon(QIcon::fromTheme("list-add"));
    ui->removeButton->setIcon(QIcon::fromTheme("list-remove"));

    // Categories
    m_catModel = new BackgroundCategoriesModel(this);
    ui->categoriesTreeView->header()->hide();
    ui->categoriesTreeView->setModel(m_catModel);
    ui->categoriesTreeView->expandAll();

    // Backgrounds
    m_model = new BackgroundsModel(this);
    ui->backgroundsIconView->setItemDelegate(new BackgroundItemDelegate(this));
    ui->backgroundsIconView->setModel(m_model);

    connect(ui->backgroundModeCombo, SIGNAL(currentIndexChanged(int)),
            this, SLOT(slotBackgroundModeSelected(int)));
    connect(ui->categoriesTreeView, SIGNAL(clicked(QModelIndex)),
            this, SLOT(slotBackgroundCategorySelected(QModelIndex)));
    connect(ui->backgroundsIconView, SIGNAL(clicked(QModelIndex)),
            this, SLOT(slotBackgroundSelected(QModelIndex)));
    connect(ui->changePictureCheckBox, SIGNAL(toggled(bool)),
            ui->changePictureComboBox, SLOT(setEnabled(bool)));
}

Preflet::~Preflet()
{
    delete ui;
    delete m_catModel;
    delete m_model;
}

void Preflet::slotBackgroundModeSelected(int index)
{
}

void Preflet::slotBackgroundCategorySelected(const QModelIndex &index)
{
    // Ignore root elements because they don't contain any image
    if (index.parent().isValid())
        m_model->setPath(m_catModel->data(index, BackgroundCategoriesModel::AbsolutePath).toString());
}

void Preflet::slotBackgroundSelected(const QModelIndex &index)
{
    if (!index.isValid())
        return;

    //QString path = m_model->data(index, BackgroundsModel::AbsolutePath).toString();
}

#include "moc_preflet.cpp"