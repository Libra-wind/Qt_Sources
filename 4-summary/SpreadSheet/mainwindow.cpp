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

    openAction = new QAction(tr("&Open"), this);
    openAction->setIcon(QIcon(":/icons/open.png"));
    openAction->setStatusTip(tr("Open a exist file"));
    openAction->setShortcut(QKeySequence::Open);

    saveAction = new QAction(tr("&Save"), this);
    saveAction->setIcon(QIcon(":/icons/save.png"));
    saveAction->setStatusTip(tr("Save file"));
    saveAction->setShortcut(tr("Ctrl+S"));


    saveasAction = new QAction(tr("Save &As..."), this);
    saveasAction->setStatusTip(tr("Save file As"));
//    saveasAction->setShortcut(tr("Ctrl+S"));

    exitAction = new QAction(tr("&Exit"), this);
    exitAction->setStatusTip(tr("Exit the application"));
    exitAction->setShortcut(tr("Ctrl+Q"));
    connect(exitAction, SIGNAL(triggered(bool)), this, SLOT(close()));

    //菜单部分
    //文件
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAction);
    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
    fileMenu->addAction(saveasAction);
    fileMenu->addSeparator();

    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);



    editMenu = menuBar()->addMenu(tr("&Edit"));

    cutAction = new QAction(tr("Cu&t"), this);
    cutAction->setIcon(QIcon(":/icons/cut.png"));
    cutAction->setShortcut(QKeySequence::Cut);

    copyAction = new QAction(tr("&Copy"), this);
    copyAction->setIcon(QIcon(":/icons/copy.png"));
    copyAction->setShortcut(QKeySequence::Copy);

    pasteAction = new QAction(tr("&Paste"), this);
    pasteAction->setIcon(QIcon(":/icons/paste.png"));
    pasteAction->setShortcut(QKeySequence::Paste);

    delAction = new QAction(tr("&Delete"), this);
    delAction->setShortcut(QKeySequence::Delete);

    //selAction = new QAction(tr("&Select"), this);

    findAction = new QAction(tr("&Find.."), this);
    findAction->setShortcut(tr("Ctrl+F"));
    findAction->setIcon(QIcon(":/icons/find.png"));


    go2cellAction = new QAction(tr("&Go to Cell.."), this);
    go2cellAction->setShortcut(tr("Ctrl+G"));
    go2cellAction->setIcon(QIcon(":/icons/go2cell.png"));

    editMenu->addAction(cutAction);
    editMenu->addAction(copyAction);
    editMenu->addAction(pasteAction);
    editMenu->addAction(delAction);
    selSubMenu = editMenu->addMenu(tr("&Select"));

    selRowAction = new QAction(tr("&Row"), this);
    selColAction = new QAction(tr("&Column"), this);
    selAllAction = new QAction(tr("&All"), this);
    selAllAction->setShortcut(tr("Ctrl+A"));
    selSubMenu->addAction(selRowAction);
    selSubMenu->addAction(selColAction);
    selSubMenu->addAction(selAllAction);

    editMenu->addSeparator();
    editMenu->addAction(findAction);
    editMenu->addAction(go2cellAction);


//    menuBar()->addMenu(tr("&Tools"));
    optMenu = menuBar()->addMenu(tr("&Options"));

    showGridAction = new QAction(tr("&Show Grid"), this);
    showGridAction->setCheckable(true);
    showGridAction->setChecked(true);
    connect(showGridAction, SIGNAL(toggled(bool)), spreadsheet, SLOT(setShowGrid(bool)));


    autoRclAction = new QAction(tr("&Auto-&Recalclate"), this);
    autoRclAction->setCheckable(true);

    optMenu->addAction(showGridAction);
    optMenu->addAction(autoRclAction);

    //工具菜单
    toolMenu = menuBar()->addMenu(tr("&Tool"));
    recAction = new QAction(tr("&Recalculate"), this);
    recAction->setShortcut(tr("F9"));

    sortAction = new QAction(tr("&Sort..."), this);
    toolMenu->addAction(recAction);
    toolMenu->addAction(sortAction);

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

