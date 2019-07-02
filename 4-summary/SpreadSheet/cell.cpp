#include<QtGui>
#include "cell.h"

Cell::Cell()
{
    getCountValue();
    setDirty();

}

Cell::~Cell()
{
    qDebug() << count << endl;
}

void Cell::setDirty()
{
    cacheIsDirty = true;
}


QTableWidgetItem* Cell::clone() const
{
    return new Cell(*this);

}

QString Cell::formula() const
{
//    qDebug() << "Cell formula" << endl;
    return data(Qt::EditRole).toString();

}

void Cell::setFormula(const QString &formula)
{
    setData(Qt::EditRole, formula);

}

void Cell::setData(int role, const QVariant &value)
{
    QTableWidgetItem::setData(role, value);
    if(role == Qt::EditRole)
        setDirty();
}

QVariant Cell::data(int role) const
{
//    qDebug() << "Cell data" << endl;
    if(Qt::DisplayRole == role)
    {
        if(value().isValid()){
            return value().toString();
        }
        else
            return "####";
    }
    else if (Qt::TextAlignmentRole == role)
    {
        if(value().type() == QVariant::String)
            return int(Qt::AlignLeft | Qt::AlignVCenter);
        else
            return int(Qt::AlignRight | Qt::AlignVCenter);
    }
    else
        return QTableWidgetItem::data(role);
}
int Cell::count = 0;
int Cell::getCountValue()
{
    count++;
}

const QVariant Invalid;
QVariant Cell::value() const
{
//    qDebug() << "Cell value" << endl;
    if(cacheIsDirty)
    {
        cacheIsDirty = false;
        QString formulaStr = formula();

        if(formulaStr.startsWith('\''))
        {
            cacheValue = formulaStr.mid(1);

        }
        else
        {
            bool ok;
            double d= formulaStr.toDouble(&ok);
            if(ok)
            {
                cacheValue = d;
            }
            else
            {
                cacheValue = formulaStr;
            }
        }




    }
    return cacheValue;
}


