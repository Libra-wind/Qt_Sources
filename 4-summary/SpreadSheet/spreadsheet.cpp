#include <QtGui>

#include "spreadsheet.h"
#include "cell.h"

Spreadsheet::Spreadsheet(QWidget *parent):QTableWidget(parent)
{
    setItemPrototype(new Cell);
    setSelectionMode(ContiguousSelection);

    clear();



}

void Spreadsheet::clear()
{
    setRowCount(0);
    setColumnCount(0);
    setRowCount(RowCount);
    setColumnCount(ColumnCount);

    for(int i = 0; i < ColumnCount; i++)
    {
        QTableWidgetItem *Item = new QTableWidgetItem;
        Item->setText(QString(QChar('A'+ i )));
        setHorizontalHeaderItem(i, Item);



    }
    setCurrentCell(0,0);
}

