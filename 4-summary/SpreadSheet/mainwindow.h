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
    QAction* openAction;
    QAction* exitAction;
    QAction* saveAction;
    QAction* saveasAction;


    QMenu* toolMenu;
    QAction* recAction;
    QAction* sortAction;

    QMenu *helpMenu;
    QAction *aboutAction;
    QAction *aboutQtAction;



    QMenu* editMenu;

    QAction* cutAction;
    QAction* copyAction;
    QAction* pasteAction;
    QAction* delAction;
//    QAction* selAction;
    QAction* findAction;
    QAction* go2cellAction;

    QMenu* selSubMenu;
    QAction* selRowAction;
    QAction* selColAction;
    QAction* selAllAction;

    QMenu* optMenu;
    QAction* showGridAction;
    QAction* autoRclAction;

    bool okTocontinue();
};

#endif // MAINWINDOW_H
