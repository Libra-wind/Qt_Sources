#include <QtGui>

#include "spreadsheet.h"
#include "cell.h"

Spreadsheet::Spreadsheet(QWidget *parent):QTableWidget(parent)
{
    setItemPrototype(new Cell);
    setSelectionMode(ContiguousSelection);

    connect(this, SIGNAL(itemChanged(QTableWidgetItem*)), this, SLOT(somethingChange()));

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

QString Spreadsheet::currentLocation() const
{
    return QChar('A'+currentColumn())+QString::number(currentRow()+1);
}

void Spreadsheet::somethingChange()
{
    emit Spreadsheet::modified();
}

Cell *Spreadsheet::cell(int row, int col) const
{
    return static_cast<Cell *>(item(row, col));
}

QString Spreadsheet::text(int row, int col) const
{
    Cell *c = cell(row, col);
    if(c == NULL)
        return "";
    else
        return c->text();
}

QString Spreadsheet::formula(int row, int col) const
{
    Cell *c = cell(row, col);
    qDebug() << "Spreadsheet formula" << endl;
    if(c == NULL)
        return "";
    else
        return c->formula();

}

void Spreadsheet::setFormula(int row, int col, const QString &formula)
{
    Cell* c = cell(row, col);
    if(!c)
    {
        c = new Cell;
        setItem(row, col, c);
    }
    c->setFormula(formula);

}

