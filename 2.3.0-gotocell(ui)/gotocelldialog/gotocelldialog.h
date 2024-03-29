#ifndef GOTOCELLDIALOG_H
#define GOTOCELLDIALOG_H

#include <QDialog>
#include "ui_gotocelldialog.h"
/*
    QT通过信号与槽机制来实现通信的功能。当该类派生自QObject并且在头文件中添加Q_OBJECT宏以后，就可以使用信号与槽。

        信号与槽之间可以进行通信的根本原因是：当在类的头文件中添加Q_OBJECT以后QtCreator会自动的创建一个moc_***.cpp文件，
    用于实现信号与槽通信的代码。但是，有时当我们通过QtCreator创建类的时候，没有通过IDE选项选择其派生自QObject类，
    而是在后面添加的，则会出现QtCreator没有自动创建moc_***.cpp文件的情况。

    这种情况下就会报错 : undefined reference to `vtable for ***

    解决方法：

        从QtCreator去除该类的头文件，然后再通过“添加现有文件”的方法，将该头文件添加进来。这样QtCreator就会自动为该类创建moc_***.cpp文件。
*/

class GoToCellDialog : public QDialog, public Ui::GoToCellDialog
{
    Q_OBJECT
public:
    GoToCellDialog(QWidget *parent = 0);
public slots:
    void on_lineEdit_textChanged();

};

#endif // GOTOCELLDIALOG_H
