#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>
#include <QPushButton>


class MyDialog : public QWidget
{
public:
    MyDialog();
private:
    QPushButton* colorbutton;

};


#endif // MYDIALOG_H
