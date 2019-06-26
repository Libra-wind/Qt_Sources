#include <QtGui>
#include "spreadsheet.h"
#include "mainwindow.h"

MainWindow::MainWindow()
{
    spreadsheet = new Spreadsheet(this);

    setCentralWidget(spreadsheet);

    newAction = new QAction(tr("&New"), this);
    newAction->setIcon(QIcon(":/icons/new.png"));
    newAction->setStatusTip(tr("Create a new file"));
    newAction->setShortcut(QKeySequence::New);

    exitAction = new QAction(tr("&Exit"), this);
    exitAction->setStatusTip(tr("Exit the application"));
    exitAction->setShortcut(tr("Ctrl+Q"));
    connect(exitAction, SIGNAL(triggered(bool)), this, SLOT(close()));

    //菜单部分
    //文件
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAction);
    fileMenu->addAction(exitAction);
    menuBar()->addMenu(tr("&Edit"));
    menuBar()->addMenu(tr("&Tools"));
    menuBar()->addMenu(tr("&Options"));

    //帮助
    helpMenu = menuBar()->addMenu(tr("&Help"));


    //状态栏
    locationLabel = new QLabel(tr(" W999 "));
    locationLabel->setAlignment(Qt::AlignCenter);
    locationLabel->setMinimumSize(locationLabel->sizeHint());
    //创建并设置动作
    aboutAction = new QAction(tr("&About"), this);
    aboutAction->setStatusTip(tr("About SpreadSheet"));

    aboutQtAction = new QAction(tr("About &Qt"), this);
    aboutQtAction->setStatusTip(tr("About Qt"));
    connect(aboutQtAction, SIGNAL(triggered(bool)), qApp, SLOT(aboutQt()));

    helpMenu->addAction(aboutAction);
    helpMenu->addAction(aboutQtAction);


    formulaLabel = new QLabel;
    formulaLabel->setIndent(3);

    statusBar()->addWidget(locationLabel);
    statusBar()->addWidget(formulaLabel, 1);

    //设置窗口图标
    setWindowIcon(QIcon(":/icons/icon.png"));
}

