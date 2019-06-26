#include<QtGui>
#include "cell.h"

Cell::Cell()
{
    setDirty();

}

void Cell::setDirty()
{
    cacheIsDirty = true;
}


QTableWidgetItem* Cell::clone() const
{
    return new Cell(*this);

}
