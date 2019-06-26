#include <QtGui>
#include "cell.h"

Cell::Cell()
{
    setDirty();
}

QTableWidgetItem *Cell::clone() const
{
    return new Cell(*this);
}

void Cell::setDirty()
{
    cacheIsDirty = true;

}

