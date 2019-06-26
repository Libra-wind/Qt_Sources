#ifndef CELL_H
#define CELL_H
#include <QTableWidgetItem>

class Cell : public QTableWidgetItem
{
public:
    Cell();
    QTableWidgetItem *clone() const;
    void setDirty();

private:
    mutable QVariant cachedValue;
    mutable bool cacheIsDirty;
};


#endif // CELL_H
