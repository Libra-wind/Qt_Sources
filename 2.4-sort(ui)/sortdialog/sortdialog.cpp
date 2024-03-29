#include <QtGui>
#include "sortdialog.h"


SortDialog::SortDialog(QWidget *parent):QDialog(parent)
{
    //importance
    setupUi(this);

    groupBox_2->hide();
    groupBox_3->hide();
    layout()->setSizeConstraint(QLayout::SetFixedSize);

    setColumnRange('A', 'Z');
}

void SortDialog::setColumnRange(QChar first, QChar last)
{
    comboBox->clear();
    comboBox_2->clear();
    comboBox_3->clear();

    comboBox_2->addItem(tr("None"));
    comboBox_3->addItem(tr("None"));
    comboBox->setMinimumSize(comboBox_2->sizeHint());


    QChar ch = first;
    while(ch <= last)
    {
        comboBox->addItem(QString(ch));
        comboBox_2->addItem(QString(ch));
        comboBox_3->addItem(QString(ch));
        ch = ch.unicode()+1;

    }

}


