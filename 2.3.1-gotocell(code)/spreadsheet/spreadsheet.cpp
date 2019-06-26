#include <QtGui>
#include <QTableWidgetItem>
#include "spreadsheet.h"

Spreadsheet::Spreadsheet(QWidget *parent):QTableWidget(parent)
{
    autoRecalc = true;

    setItemPrototype(new QTableWidgetItem);
    setSelectionMode(QAbstractItemView::ContiguousSelection);

    //connect(this, SIGNAL(itemChanged(QTableWidgetItem*)), this, SLOT(somethingChanged()));


}

void Spreadsheet::clear()
{
    setRowCount(0);
    setColumnCount(0);
    setRowCount(RowCount);
    setColumnCount(ColumnCount);

    for(int i = 0; i < ColumnCount; ++i)
    {
        QTableWidgetItem *item = new QTableWidgetItem;
        item->setText(QString(QChar('A' + i)));
        setHorizontalHeaderItem(i, item);
    }
    setCurrentCell(0,0);

}

