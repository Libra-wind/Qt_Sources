#include <QtGui>
#include "gotocell.h"



GoToCellDialog::GoToCellDialog(QWidget *parent):QDialog(parent)
{
    okButton = new QPushButton(tr("OK"));

    okButton->setEnabled(false);
    okButton->setDefault(true);

    cancelButton = new QPushButton(tr("Cancel"));
    m_label = new QLabel(tr("&Cell Location"));

    m_lineEdit = new QLineEdit;
    m_label->setBuddy(m_lineEdit);

    QHBoxLayout *topLayout = new QHBoxLayout;
    topLayout->addWidget(m_label);
    topLayout->addWidget(m_lineEdit);

    QHBoxLayout *BottomLayout = new QHBoxLayout;
    BottomLayout->addStretch();
    BottomLayout->addWidget(okButton);
    BottomLayout->addWidget(cancelButton);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(topLayout);
    mainLayout->addLayout(BottomLayout);

    setLayout(mainLayout);


    connect(cancelButton, SIGNAL(clicked(bool)),
            this, SLOT(reject()));
    connect(okButton, SIGNAL(clicked(bool)),
            this, SLOT(accept()));
    connect(m_lineEdit, SIGNAL(textChanged(QString)),
            this, SLOT(SetButtonEnable(QString)));

}

void GoToCellDialog::SetButtonEnable(const QString &str)
{
    if(!str.isEmpty())
        okButton->setEnabled(true);
}





