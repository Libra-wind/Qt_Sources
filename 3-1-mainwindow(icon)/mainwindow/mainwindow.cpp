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


    aboutQtAction = new QAction(tr("About &Qt"), this);
    aboutQtAction->setStatusTip(tr("Show the Qt Library's About box"));
    aboutQtAction->setIcon(QIcon(":/images/notebook.png"));
    connect(aboutQtAction, SIGNAL(triggered(bool)), qApp, SLOT(aboutQt()));

    exitQtAction = new QAction(tr("&Exit"), this);
    exitQtAction->setShortcut(tr("Ctrl+Q"));
    exitQtAction->setStatusTip("Exit the applicatio");
    connect(exitQtAction, SIGNAL(triggered(bool)), this, SLOT(close()));

    fileMenu = menuBar()->addMenu(tr("&File"));

    fileMenu->addAction(aboutQtAction);
    fileMenu->addSeparator();//加入分割线
    fileMenu->addAction(exitQtAction);

    addAction(exitQtAction);
    setContextMenuPolicy(Qt::ActionsContextMenu);

    fileToolBar = addToolBar(tr("&File"));
    fileToolBar->addAction(aboutQtAction);



}

MainWindow::~MainWindow()
{
    delete ui;
}
