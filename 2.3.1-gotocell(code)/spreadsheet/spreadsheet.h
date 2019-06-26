#ifndef SPREADSHEET_H
#define SPREADSHEET_H

#include <QTableWidget>
class Cell;

class Spreadsheet:public QTableWidget
{
    Q_OBJECT
public:
    Spreadsheet(QWidget *parent =0);
    void clear();
#if 0
signals:
    void modified();
private slots:
    void somethingChanged();
#endif
private:
    enum{ MagicNumber = 0x7F51C883, RowCount = 999, ColumnCount = 26};
    Cell *cell(int row, int column) const;
    QString text(int row, int column) const;
    QString formula(int row, int column) const;
    void setFormula(int row, int column, const QString &formula);
    bool autoRecalc;

};


#endif // SPREADSHEET_H
