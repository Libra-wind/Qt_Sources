#ifndef SPREADSHEET_H
#define SPREADSHEET_H

#include <QTableWidget>

class Cell;
class Spreadsheet;

class Spreadsheet : public QTableWidget
{
    Q_OBJECT
public:
    Spreadsheet(QWidget *parent = 0);
    void clear();
    bool writeFile(const QString &filename);
    bool readFile(const QString &filename);
    QString currentLocation() const;
    QString currentFormula() const;
    QTableWidgetSelectionRange selectedRange() const;
signals:
    void modified();
private slots:
    void somethingChange();
    void cut();
    void copy();
    void paste();
    void del();
    void selectCurRow();
    void selectCurCol();
private:
    enum{
        MagicNumber = 0x7F51C883,
        RowCount = 999,
        ColumnCount = 26,
    };
    Cell* cell(int row, int col) const;
    QString text(int row, int col) const;
    QString formula(int row, int col) const;
    void setFormula(int row, int col, const QString &formula);
};



#endif // SPREADSHEET_H
