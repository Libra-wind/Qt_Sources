#include <QtGui>
#include "gotocelldialog.h"
#if 1
GoToCellDialog::GoToCellDialog(QWidget *parent):QDialog(parent)
{
    setupUi(this);
    QRegExp regExp("[A-Za-z][1-9][0-9]{0,2}");

    lineEdit->setValidator(new QRegExpValidator(regExp,this));

    connect(okButton, SIGNAL(clicked(bool)), this, SLOT(accept()));
    connect(cancelButton, SIGNAL(clicked(bool)), this, SLOT(reject()));

}

#endif

void GoToCellDialog::on_lineEdit_textChanged()
{
    okButton->setEnabled(lineEdit->hasAcceptableInput());
}
