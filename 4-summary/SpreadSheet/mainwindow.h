#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class QAction;
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

    QMenu *fileMenu;



    QAction* newAction;
    QAction* exitAction;


    QMenu *helpMenu;
    QAction *aboutAction;
    QAction *aboutQtAction;
};

#endif // MAINWINDOW_H
