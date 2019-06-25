#include <QtGui>
#include "mainwindow.h"
#include "ui_mainwindow.h"

//使用图标的方法
/* 1、源代码目录下新建文件夹，
 * 2、编写.qrc文件
 * 3、pro文件添加资源文件声明
 * 4、调用setsetWindowIcon(QIcon(":/图标路径"));
 *
 */


/*          使用菜单的步骤
 * 1、创建并设置动作（shortcut）
 * 2、创建菜单并添加动作（menuBar()->addMenu）
 *
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("图标测试窗口"));
    setWindowIcon(QIcon(":/images/folder.png"));

    fileNewAction = new QAction(tr("&New"), this);
    fileNewAction->setShortcut(QKeySequence::New);
    fileNewAction->setStatusTip(tr("Create a New file"));
    //setCentralWidget(spreadsheet);
    connect(fileNewAction, SIGNAL(triggered(bool)), this, SLOT(newfile()));

    aboutQtAction = new QAction(tr("About &Qt"), this);
    aboutQtAction->setStatusTip(tr("Show the Qt Library's About box"));
    aboutQtAction->setIcon(QIcon(":/images/notebook.png"));
    connect(aboutQtAction, SIGNAL(triggered(bool)), qApp, SLOT(aboutQt()));

    openQtAction = new QAction(tr("&Open"), this);
    openQtAction->setShortcut(tr("Ctrl+O"));
    openQtAction->setStatusTip(tr("Open a exist file"));
    connect(openQtAction, SIGNAL(triggered(bool)), this, SLOT(openfile()));


    exitQtAction = new QAction(tr("&Exit"), this);
    exitQtAction->setShortcut(tr("Ctrl+Q"));
    exitQtAction->setStatusTip("Exit the applicatio");
    connect(exitQtAction, SIGNAL(triggered(bool)), this, SLOT(close()));

    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(fileNewAction);
    fileMenu->addAction(openQtAction);
    fileMenu->addAction(aboutQtAction);
    fileMenu->addSeparator();//加入分割线
    fileMenu->addAction(exitQtAction);

    addAction(exitQtAction);
    setContextMenuPolicy(Qt::ActionsContextMenu);

    locationLabel = new QLabel(tr(" W999 "));
    locationLabel->setAlignment(Qt::AlignHCenter);
    locationLabel->setMinimumSize(locationLabel->sizeHint());

    formulaLabel = new QLabel;
    formulaLabel->setIndent(3);

    statusBar()->addWidget(locationLabel);
    statusBar()->addWidget(formulaLabel,1);


    fileToolBar = addToolBar(tr("&File"));
    fileToolBar->addAction(aboutQtAction);



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newfile()
{
    if(okTocontinue())
    {
        qDebug() << "成功新建" << endl;

    }
}

void MainWindow::openfile()
{
    if(okTocontinue())
    {
        QString filename = QFileDialog::getOpenFileName(this, tr("Open Spreadsheet"), ".",
                                                        tr("Spreadsheet file(*.png)"));
        if(!filename.isEmpty())
        {
            qDebug() << filename << endl;
        }
        else
            qDebug() << filename << endl;
    }

}

bool MainWindow::okTocontinue()
{

    if(1)
    {
        int res = QMessageBox::warning(this, tr("SpreadSheet"),
                                       tr("The document has been modified.\n"
                                          "Do you want to save your changes?"),
                                       QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
        if(res == QMessageBox::Yes)
        {
            qDebug() << "Yes" << endl;
            return true;
        }
        else if(res == QMessageBox::Cancel)
            return false;


    }
    return true;

}
