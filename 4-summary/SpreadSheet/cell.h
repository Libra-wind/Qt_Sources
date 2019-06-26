#ifndef CELL_H
#define CELL_H

#include <QTableWidgetItem>

class Cell : public QTableWidgetItem
{
public:
    Cell();
    void setDirty();
    QTableWidgetItem* clone() const;

private:
    mutable bool cacheIsDirty;


};



#endif // CELL_H
