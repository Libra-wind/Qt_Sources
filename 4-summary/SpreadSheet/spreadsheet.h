#ifndef SPREADSHEET_H
#define SPREADSHEET_H

#include <QTableWidget>

class Cell;
class Spreadsheet;

class Spreadsheet : public QTableWidget
{
public:
    Spreadsheet(QWidget *parent = 0);
    void clear();
private:
    enum{
        MagicNumber = 0x7F51C883,
        RowCount = 999,
        ColumnCount = 26,
    };
};



#endif // SPREADSHEET_H
