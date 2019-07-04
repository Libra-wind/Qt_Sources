#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    quitButton = new QPushButton(tr("quit"), this);

    connect(quitButton, SIGNAL(clicked(bool)), this, SLOT(close()));

#if 1
    resize(quitButton->sizeHint());
#endif
}

Widget::~Widget()
{
    delete ui;
}
