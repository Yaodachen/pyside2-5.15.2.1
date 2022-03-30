/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of Qt for Python.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

/*
  model.cpp

  A simple model that uses a QStringList as its data source.
*/

/*!
    Returns the number of items in the string list as the number of rows
    in the model.
*/

//! [0]
def rowCount(self, parent):
    return len(self.stringList)
//! [0]

/*!
    Returns an appropriate value for the requested data.
    If the view requests an invalid index, an invalid variant is returned.
    Any valid index that corresponds to a string in the list causes that
    string to be returned.
*/

//! [1]
def data(self, index, role):
    if not index.isValid():
        return None

    if index.row() >= stringList.size():
        return None

    if role == Qt.DisplayRole:
        return stringList[index.row()]
    else
        return None
//! [1]

/*!
    Returns the appropriate header string depending on the orientation of
    the header and the section. If anything other than the display role is
    requested, we return an invalid variant.
*/

//! [2]
def headerData(self, section, orientation, role):
    if role != Qt::DisplayRole:
        return None

    if orientation == Qt::Horizontal:
        return "Column %s" % section
    else:
        return "Row %s" % section
//! [2]

/*!
    Returns an appropriate value for the item's flags. Valid items are
    enabled, selectable, and editable.
*/

//! [3]
def flags(self, index):
    if not index.isValid()
        return Qt.ItemIsEnabled

    return QAbstractItemModel.flags(index) | Qt.ItemIsEditable
//! [3]

/*!
    Changes an item in the string list, but only if the following conditions
    are met:

    * The index supplied is valid.
    * The index corresponds to an item to be shown in a view.
    * The role associated with editing text is specified.

    The dataChanged() signal is emitted if the item is changed.
*/

//! [4]
def setData(self, index, value, role):
    if index.isValid() and role == Qt.EditRole:
        self.stringList[index.row()] = value
        self.dataChanged.emit(index, index)
        return True;
//! [4] //! [5]
    return False;
}
//! [5]

/*!
    Inserts a number of rows into the model at the specified position.
*/

//! [6]
def insertRows(self, position, rows, parent):
    self.beginInsertRows(QModelIndex(), position, position+rows-1)

    for row in range(0, rows):
        self.stringList.insert(position, "")

    self.endInsertRows()
    return True;
//! [6] //! [7]
//! [7]

/*!
    Removes a number of rows from the model at the specified position.
*/

//! [8]
def removeRows(self, position, rows, parent):
    self.beginRemoveRows(QModelIndex(), position, position+rows-1)

    for row in range(0, rows):
        del self.stringList[position]

    self.endRemoveRows()
    return True;
//! [8] //! [9]
//! [9]
