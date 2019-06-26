#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class Spreadsheet;
class QLabel;
class MainWindow : public QMainWindow
{
public:
    MainWindow();

private:
    Spreadsheet *spreadsheet;
    QLabel *locationLabel;
    QLabel *formulaLabel;
};

#endif // MAINWINDOW_H
