#include<QApplication>
#include "spreadsheet.h"
#include "mainwindow.h"
int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    MainWindow *w = new MainWindow;
    //Spreadsheet *p_sheet = new Spreadsheet;
    w->show();



    return app.exec();
}

