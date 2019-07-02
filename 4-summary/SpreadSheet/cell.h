#ifndef CELL_H
#define CELL_H

#include <QTableWidgetItem>

class Cell : public QTableWidgetItem
{
public:
    Cell();
    ~Cell();
    void setDirty();
    QTableWidgetItem* clone() const;
    QString formula() const;
    void setFormula(const QString &formula);
    void setData(int role, const QVariant &value);
    QVariant data(int role) const;
    static int getCountValue();
private:

    QVariant value() const;
    static int count;
    mutable bool cacheIsDirty;
    mutable QVariant cacheValue;

};



#endif // CELL_H
