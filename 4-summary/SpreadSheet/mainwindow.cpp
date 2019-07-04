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
    connect(newAction, SIGNAL(triggered(bool)), this, SLOT(newFile()));
    openAction = new QAction(tr("&Open"), this);
    openAction->setIcon(QIcon(":/icons/open.png"));
    openAction->setStatusTip(tr("Open a exist file"));
    openAction->setShortcut(QKeySequence::Open);
    connect(openAction, SIGNAL(triggered(bool)), this, SLOT(open()));


    saveAction = new QAction(tr("&Save"), this);
    saveAction->setIcon(QIcon(":/icons/save.png"));
    saveAction->setStatusTip(tr("Save file"));
    saveAction->setShortcut(tr("Ctrl+S"));
    connect(saveAction, SIGNAL(triggered(bool)), this, SLOT(save()));

    saveasAction = new QAction(tr("Save &As..."), this);
    saveasAction->setStatusTip(tr("Save file As"));
    connect(saveasAction, SIGNAL(triggered(bool)), this, SLOT(saveAs()));

    for(int i = 0; i < MaxRecentFiles; i++ )
    {
        recentFileActions[i] = new QAction(this);
        recentFileActions[i]->setVisible(false);
        connect(recentFileActions[i], SIGNAL(triggered(bool)),
                this, SLOT(openRecentFile()));
    }


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
    separatorAction = fileMenu->addSeparator();
    for(int i = 0; i < MaxRecentFiles; i++)
    {
        fileMenu->addAction(recentFileActions[i]);
    }
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);



    editMenu = menuBar()->addMenu(tr("&Edit"));

    cutAction = new QAction(tr("Cu&t"), this);
    cutAction->setIcon(QIcon(":/icons/cut.png"));
    cutAction->setShortcut(QKeySequence::Cut);
    connect(cutAction, SIGNAL(triggered(bool)), spreadsheet, SLOT(cut()));
    copyAction = new QAction(tr("&Copy"), this);
    copyAction->setIcon(QIcon(":/icons/copy.png"));
    copyAction->setShortcut(QKeySequence::Copy);
    connect(copyAction, SIGNAL(triggered(bool)), spreadsheet, SLOT(copy()));
    pasteAction = new QAction(tr("&Paste"), this);
    pasteAction->setIcon(QIcon(":/icons/paste.png"));
    pasteAction->setShortcut(QKeySequence::Paste);
    connect(pasteAction, SIGNAL(triggered(bool)), spreadsheet, SLOT(paste()));
    delAction = new QAction(tr("&Delete"), this);
    delAction->setShortcut(QKeySequence::Delete);
    connect(delAction, SIGNAL(triggered(bool)), spreadsheet, SLOT(del()));
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
    connect(selRowAction, SIGNAL(triggered(bool)), spreadsheet, SLOT(selectCurRow()));
    selColAction = new QAction(tr("&Column"), this);
    connect(selColAction, SIGNAL(triggered(bool)), spreadsheet, SLOT(selectCurCol()));
    selAllAction = new QAction(tr("&All"), this);    
    selAllAction->setShortcut(tr("Ctrl+A"));
    connect(selAllAction, SIGNAL(triggered(bool)), spreadsheet, SLOT(selectAll()));
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

    connect(spreadsheet, SIGNAL(currentCellChanged(int,int,int,int)), this, SLOT(updateStatusBar()));
    connect(spreadsheet, SIGNAL(modified()),
            this, SLOT(spreadsheetModified()));
    //设置窗口图标
    setWindowIcon(QIcon(":/icons/icon.png"));


    spreadsheet->addAction(cutAction);
    spreadsheet->addAction(copyAction);
    spreadsheet->addAction(pasteAction);

    spreadsheet->setContextMenuPolicy(Qt::ActionsContextMenu);

    readSettings();


    updateStatusBar();

    setCurFile("");
}

void MainWindow::newFile()
{
    if(okTocontinue())
    {
        spreadsheet->clear();
        setCurFile("");
    }
}

void MainWindow::open()
{
    if(okTocontinue())
    {
        QString fileName = QFileDialog::getOpenFileName(this,
                                                        tr("Open Spreadsheet"), "F:/Qt/Qt_Sources/4-summary/testfile/",
                                                        tr("Spreadsheet files(*.sp)"));
        if(!fileName.isEmpty())
        {
            loadFile(fileName);
        }
    }
}

bool MainWindow::save()
{
    if(curFile.isEmpty())
    {
        return saveAs();
    }
    else
        return saveFile(curFile);
}

bool MainWindow::saveFile(const QString &filename)
{
    if(!spreadsheet->writeFile(filename))
    {
        statusBar()->showMessage(tr("Saving canceled"), 2000);
        return false;
    }

    setCurFile(filename);
    statusBar()->showMessage(tr("File saved"), 2000);
    return true;
}

bool MainWindow::saveAs()
{
    QString filename = QFileDialog::getSaveFileName(this, tr("Save Spreadsheet"), "F:/Qt/Qt_Sources/4-summary/testfile/",
                                                    tr("Spreadsheet files (*.sp)"));
    if(filename.isEmpty())
        return false;
    return saveFile(filename);
}

void MainWindow::openRecentFile()
{
    if(okTocontinue())
    {
        QAction *action = qobject_cast<QAction*>(sender());
        if(action)
            loadFile(action->data().toString());
    }
}

bool MainWindow::loadFile(const QString &fileName)
{
    if(!spreadsheet->readFile(fileName))
    {
        statusBar()->showMessage(tr("Loading canceled"), 2000);
        return false;
    }

    setCurFile(fileName);
    statusBar()->showMessage(tr("File loaded"), 2000);
    return true;
}

void MainWindow::writeSettings()
{
    QSettings settings("Software Inc.", "Spreadsheet");

    settings.setValue("geometry", saveGeometry());
    settings.setValue("recentFiles", recentFiles);
    settings.setValue("showGrid", showGridAction->isChecked());
    settings.setValue("autoRecalc", autoRclAction->isChecked());
}

void MainWindow::readSettings()
{
    QSettings setting("Software Inc.", "Spreadsheet");

    restoreGeometry(setting.value("geometry").toByteArray());

    recentFiles = setting.value("recentFiles").toStringList();
    updateRecentFileActions();

    bool showGrid = setting.value("showGrid", true).toBool();
    showGridAction->setChecked(showGrid);

    bool autoRecalc = setting.value("autoRecalc", true).toBool();
    autoRclAction->setChecked(autoRecalc);


}

void MainWindow::setCurFile(const QString &filename)
{
    curFile = filename;
    setWindowModified(false);
    QString shownName = tr("Untitled");
    if(!curFile.isEmpty())
    {
        shownName = strippedName(curFile);
        recentFiles.removeAll(curFile);
        recentFiles.prepend(curFile);
//        qDebug() << recentFiles.count() << endl;
        updateRecentFileActions();
    }
    setWindowTitle(tr("%1[*]-%2").arg(shownName).arg(tr("Spreadsheet")));
}

QString MainWindow::strippedName(const QString &fullFileName)
{
    return QFileInfo(fullFileName).fileName();
}

void MainWindow::updateStatusBar()
{
    locationLabel->setText(spreadsheet->currentLocation());
    formulaLabel->setText(spreadsheet->currentFormula());
}

void MainWindow::spreadsheetModified()
{
    setWindowModified(true);
    updateStatusBar();
}

#if 1
bool MainWindow::okTocontinue()
{
    if(isWindowModified())
    {
        int r = QMessageBox::warning(this, tr("Spreadsheet"), tr("The document has been modified,.\nDo you want to save your change"),
                                     QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
        if(r == QMessageBox::Yes)
            return save();
        else if(r == QMessageBox::Cancel)
            return false;

    }

    return true;
}

void MainWindow::updateRecentFileActions()
{
    QMutableStringListIterator i(recentFiles);
    while(i.hasNext())
    {
        if(!QFile::exists(i.next()))
            i.remove();
    }
//    qDebug() << "316" << recentFiles.count() << endl;
    for(int j = 0; j < MaxRecentFiles; j++)
    {

        if(j < recentFiles.count())
        {

            QString text = tr("&%2").arg(strippedName(recentFiles[j]));
            recentFileActions[j]->setText(text);
            recentFileActions[j]->setData(recentFiles[j]);
            recentFileActions[j]->setVisible(true);
        }
        else
            recentFileActions[j]->setVisible(false);
    }
    separatorAction->setVisible(!recentFiles.isEmpty());
}


void MainWindow::closeEvent(QCloseEvent *event)
{
    if(okTocontinue())
    {
        writeSettings();
        event->accept();
    }
    else
        event->ignore();
}

#endif
