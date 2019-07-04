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

bool Spreadsheet::writeFile(const QString &filename)
{
    QFile file(filename);
    if(!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::warning(this, tr("Spreadsheet"), tr("Cannot write file %1:\n%2.").arg(file.fileName().arg(file.errorString())));
        return false;
    }

    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_4_3);
    out << quint32(MagicNumber);

    QApplication::setOverrideCursor(Qt::WaitCursor);
    for(int row = 0; row < RowCount; row++)
    {
        for(int col = 0; col < ColumnCount; col++)
        {
            QString str = formula(row, col);
            if(!str.isEmpty())
            {
                out << quint16(row) << quint16(col) << str;
            }
        }
    }
    QApplication::restoreOverrideCursor();
    return true;




}

bool Spreadsheet::readFile(const QString &filename)
{
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(this, tr("Spreadsheet"), tr("Cannot read %1:\n%2.").arg(file.fileName()).arg(file.errorString()));
        return false;
    }

    QDataStream in(&file);

    in.setVersion(QDataStream::Qt_4_3);
    quint32 magic;
    in >> magic;

    if(magic != MagicNumber)
    {
        QMessageBox::warning(this, tr("Spreadsheet"), tr("The file is not a Spreadsheet file."));
        return false;
    }
    clear();
    quint16 row;
    quint16 col;
    QString str;
    QApplication::setOverrideCursor(Qt::WaitCursor);
    while(!in.atEnd())
    {
        in >> row >> col >> str;

        setFormula(row, col, str);
    }
    QApplication::restoreOverrideCursor();
    return true;
}

QString Spreadsheet::currentLocation() const
{
    return QChar('A'+currentColumn())+QString::number(currentRow()+1);
}

QString Spreadsheet::currentFormula() const
{
    Cell* c = cell(currentRow(), currentColumn());
    if(c)
        return c->formula();
    else
        return "";
}

QTableWidgetSelectionRange Spreadsheet::selectedRange() const
{
    QList<QTableWidgetSelectionRange> ranges = selectedRanges();
    if(ranges.isEmpty())
        return QTableWidgetSelectionRange();
    return ranges.first();
}

void Spreadsheet::somethingChange()
{

    emit Spreadsheet::modified();
}

void Spreadsheet::cut()
{
    copy();
    del();
}

void Spreadsheet::copy()
{
    QTableWidgetSelectionRange range = selectedRange();
    QString str;

    for(int i = 0; i < range.rowCount(); i++)
    {
        if(i > 0)
            str += "\n";
        for(int j = 0; j < range.columnCount(); j++)
        {
            if(j > 0)
                str += "\t";
            str += formula(range.topRow()+i, range.leftColumn() + j);
        }

    }
    QApplication::clipboard()->setText(str);

}

void Spreadsheet::paste()
{
    QTableWidgetSelectionRange range = selectedRange();
    QString str = QApplication::clipboard()->text();
    QStringList rows = str.split('\n');
    int numRows = rows.count();
    int numCols = rows.first().count('\t') + 1;


    if(range.rowCount()*range.columnCount() != 1
            && (range.rowCount() != numRows || range.columnCount() != numCols))
    {
        QMessageBox::information(this, tr("Spreadsheet"),
                                 tr("The information connot be pasted because the copy "
                                    "and paste areas aren't the same size."));
        return;
    }


    for(int i = 0; i < numRows; i++)
    {
        QStringList cols = rows[i].split('\t');
        for(int j = 0; j < numCols; j++)
        {
            int row = range.topRow() + i;
            int column = range.leftColumn() + j;
            if(row < RowCount && column < ColumnCount)
                setFormula(row, column, cols[j]);

        }


    }

    somethingChange();
}

void Spreadsheet::del()
{
    QList<QTableWidgetItem*> items = selectedItems();
    if(items.isEmpty())
    {
        foreach (QTableWidgetItem *item, items) {
            delete item;
            somethingChange();
        }
    }
}

void Spreadsheet::selectCurRow()
{
    selectRow(currentRow());
}

void Spreadsheet::selectCurCol()
{
    selectColumn(currentColumn());
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

