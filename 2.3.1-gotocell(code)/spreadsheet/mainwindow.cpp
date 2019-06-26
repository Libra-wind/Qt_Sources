#include <QtGui>

#include "spreadsheet.h"
#include "mainwindow.h"
MainWindow::MainWindow()
{
    spreadsheet = new Spreadsheet;
    setCentralWidget(spreadsheet);
}
