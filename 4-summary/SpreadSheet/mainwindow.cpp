#include<QtGui>
#include "spreadsheet.h"
#include "mainwindow.h"

MainWindow::MainWindow()
{
    spreadsheet = new Spreadsheet(this);

    setCentralWidget(spreadsheet);

    //菜单部分
    menuBar()->addMenu(tr("&File"));
    menuBar()->addMenu(tr("&Edit"));
    menuBar()->addMenu(tr("&Tools"));
    menuBar()->addMenu(tr("&Options"));
    menuBar()->addMenu(tr("&Help"));
    //状态栏
    locationLabel = new QLabel(tr(" W999 "));
    locationLabel->setAlignment(Qt::AlignCenter);
    locationLabel->setMinimumSize(locationLabel->sizeHint());

    formulaLabel = new QLabel;
    formulaLabel->setIndent(3);

    statusBar()->addWidget(locationLabel);
    statusBar()->addWidget(formulaLabel, 1);

    //设置窗口图标
    setWindowIcon(QIcon(":/icons/icon.png"));
}

