#include <QtGui>
#include "finddialog.h"
//冒号后说明：如果基类存在有参构造函数时，则派生类需要对基类进行初始化
FindDialog::FindDialog(QWidget *parent) : QDialog(parent)
{
    m_label = new QLabel(tr("Find&what:"));
    m_lineEdit = new QLineEdit;
    //设置伙伴，就是一个窗口部件，他可以在按下标签的快捷键时接收焦点
    //按下Alt+W时,焦点会移动到这个行编辑器上。
    m_label->setBuddy(m_lineEdit);


    m_caseCheckBox = new QCheckBox(tr("Match &case"));
    m_backwardCheckBox = new QCheckBox(tr("Search &backward"));

    m_findButton = new QPushButton(tr("&Find"));
    //设置为对话框的默认按钮
    m_findButton->setDefault(true);
    //禁用按钮
    m_findButton->setEnabled(false);

    m_closeButton = new QPushButton(tr("Close"));

    connect(m_findButton, SIGNAL(clicked(bool)), this, SLOT(findClicked()));
    connect(m_closeButton, SIGNAL(clicked(bool)), this, SLOT(close()));
    connect(m_lineEdit, SIGNAL(textChanged(const QString &)),
            this, SLOT(enabledFindButton(QString)));


    QHBoxLayout *topLeftLayout = new QHBoxLayout;
    topLeftLayout->addWidget(m_label);
    topLeftLayout->addWidget(m_lineEdit);

    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout->addLayout(topLeftLayout);
    leftLayout->addWidget(m_caseCheckBox);
    leftLayout->addWidget(m_backwardCheckBox);

    QVBoxLayout *rightLayout = new QVBoxLayout;
    rightLayout->addWidget(m_findButton);
    rightLayout->addWidget(m_closeButton);
    rightLayout->addStretch();

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);
    mainLayout->addLayout(topLeftLayout);
    setLayout(mainLayout);

    setWindowTitle(tr("Find"));
    setFixedHeight(sizeHint().height());

}

void FindDialog::findClicked()
{
    QString text = m_lineEdit->text();
    Qt::CaseSensitivity cs = m_caseCheckBox->isChecked()?Qt::CaseSensitive
                                                       :Qt::CaseInsensitive;
    if(m_backwardCheckBox->isChecked())
    {
        emit findPrevious(text,cs);
    }
    else
        emit findNext(text, cs);
}

void FindDialog::enabledFindButton(const QString &str)
{
    m_findButton->setEnabled(!str.isEmpty());
}

