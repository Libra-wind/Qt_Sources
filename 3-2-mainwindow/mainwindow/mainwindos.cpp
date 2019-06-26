#include <QtGui>

#include "mainwindow.h"



MainWindow::MainWindow()
{
    setWindowTitle("Spreadsheet");
    setWindowIcon(QIcon(":/images/icon.png"));

    fileNewAction = new QAction(tr("&New"), this);
    fileNewAction->setShortcut(QKeySequence::New);
    fileNewAction->setStatusTip(tr("Create a new spreadsheet file"));
    fileNewAction->setIcon(QIcon(tr(":/images/文件.png")));


    fileOpenAction = new QAction(tr("&Open.."), this);
    fileOpenAction->setShortcut(QKeySequence::Open);
    fileOpenAction->setIcon(QIcon(tr(":/images/打开文件.png")));
    fileNewAction->setStatusTip(tr("Open a exist spreadsheet file"));

    fileSaveAction = new QAction(tr("&Save"), this);
    fileSaveAction->setShortcut(QKeySequence::Save);
    fileSaveAction->setStatusTip(tr("Save spreadsheet"));
    fileSaveAction->setIcon(QIcon(tr(":/images/保存.png")));

    fileSaveAsAction = new QAction(tr("Save &As..."), this);
    fileSaveAsAction->setShortcut(QKeySequence::SaveAs);
    fileSaveAsAction->setStatusTip(tr("Save spreadsheet as..."));

    fileExitAction = new QAction(tr("&Exit"), this);
    fileExitAction->setShortcut(tr("Ctrl+Q"));
    fileExitAction->setStatusTip(tr("Exit the application"));
    connect(fileExitAction, SIGNAL(triggered(bool)),
            this, SLOT(close()));



    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(fileNewAction);
    fileMenu->addAction(fileOpenAction);
    fileMenu->addAction(fileSaveAction);
    fileMenu->addAction(fileSaveAsAction);
    fileMenu->addAction(fileExitAction);
}


