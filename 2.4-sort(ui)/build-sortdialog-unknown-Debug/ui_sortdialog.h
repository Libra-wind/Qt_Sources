/********************************************************************************
** Form generated from reading UI file 'sortdialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SORTDIALOG_H
#define UI_SORTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SortDialog
{
public:
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QComboBox *comboBox_2;
    QVBoxLayout *verticalLayout;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QSpacerItem *verticalSpacer;
    QPushButton *moreButton;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QComboBox *comboBox_3;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_4;
    QComboBox *comboBox_4;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QLabel *label_5;
    QComboBox *comboBox_5;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_6;
    QComboBox *comboBox_6;

    void setupUi(QDialog *SortDialog)
    {
        if (SortDialog->objectName().isEmpty())
            SortDialog->setObjectName(QString::fromUtf8("SortDialog"));
        SortDialog->resize(402, 341);
        gridLayout_4 = new QGridLayout(SortDialog);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        groupBox = new QGroupBox(SortDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout->addWidget(comboBox, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(119, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        comboBox_2 = new QComboBox(groupBox);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        gridLayout->addWidget(comboBox_2, 1, 1, 1, 2);


        gridLayout_4->addWidget(groupBox, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        okButton = new QPushButton(SortDialog);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setDefault(true);

        verticalLayout->addWidget(okButton);

        cancelButton = new QPushButton(SortDialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        verticalLayout->addWidget(cancelButton);

        verticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        moreButton = new QPushButton(SortDialog);
        moreButton->setObjectName(QString::fromUtf8("moreButton"));
        moreButton->setCheckable(true);

        verticalLayout->addWidget(moreButton);


        gridLayout_4->addLayout(verticalLayout, 0, 1, 2, 1);

        verticalSpacer_2 = new QSpacerItem(20, 29, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_2, 1, 0, 1, 1);

        groupBox_2 = new QGroupBox(SortDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        comboBox_3 = new QComboBox(groupBox_2);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));

        gridLayout_2->addWidget(comboBox_3, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);

        comboBox_4 = new QComboBox(groupBox_2);
        comboBox_4->setObjectName(QString::fromUtf8("comboBox_4"));

        gridLayout_2->addWidget(comboBox_4, 1, 1, 1, 2);


        gridLayout_4->addWidget(groupBox_2, 2, 0, 1, 1);

        groupBox_3 = new QGroupBox(SortDialog);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_3->addWidget(label_5, 0, 0, 1, 1);

        comboBox_5 = new QComboBox(groupBox_3);
        comboBox_5->setObjectName(QString::fromUtf8("comboBox_5"));

        gridLayout_3->addWidget(comboBox_5, 0, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 0, 2, 1, 1);

        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_3->addWidget(label_6, 1, 0, 1, 1);

        comboBox_6 = new QComboBox(groupBox_3);
        comboBox_6->setObjectName(QString::fromUtf8("comboBox_6"));

        gridLayout_3->addWidget(comboBox_6, 1, 1, 1, 2);


        gridLayout_4->addWidget(groupBox_3, 3, 0, 1, 1);


        retranslateUi(SortDialog);
        QObject::connect(okButton, SIGNAL(clicked()), SortDialog, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), SortDialog, SLOT(reject()));
        QObject::connect(moreButton, SIGNAL(toggled(bool)), groupBox_2, SLOT(setVisible(bool)));
        QObject::connect(moreButton, SIGNAL(toggled(bool)), groupBox_3, SLOT(setVisible(bool)));

        QMetaObject::connectSlotsByName(SortDialog);
    } // setupUi

    void retranslateUi(QDialog *SortDialog)
    {
        SortDialog->setWindowTitle(QApplication::translate("SortDialog", "Sort", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("SortDialog", "&Primary Key", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SortDialog", "Column:", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("SortDialog", "None", 0, QApplication::UnicodeUTF8)
        );
        label_2->setText(QApplication::translate("SortDialog", "Order:", 0, QApplication::UnicodeUTF8));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("SortDialog", "Ascending", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SortDialog", "Descending", 0, QApplication::UnicodeUTF8)
        );
        okButton->setText(QApplication::translate("SortDialog", "OK", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("SortDialog", "Cancel", 0, QApplication::UnicodeUTF8));
        moreButton->setText(QApplication::translate("SortDialog", "&More", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("SortDialog", "&Secondary Key", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("SortDialog", "Column:", 0, QApplication::UnicodeUTF8));
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("SortDialog", "None", 0, QApplication::UnicodeUTF8)
        );
        label_4->setText(QApplication::translate("SortDialog", "Order:", 0, QApplication::UnicodeUTF8));
        comboBox_4->clear();
        comboBox_4->insertItems(0, QStringList()
         << QApplication::translate("SortDialog", "Ascending", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SortDialog", "Descending", 0, QApplication::UnicodeUTF8)
        );
        groupBox_3->setTitle(QApplication::translate("SortDialog", "&Tertiary Key", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("SortDialog", "Column:", 0, QApplication::UnicodeUTF8));
        comboBox_5->clear();
        comboBox_5->insertItems(0, QStringList()
         << QApplication::translate("SortDialog", "None", 0, QApplication::UnicodeUTF8)
        );
        label_6->setText(QApplication::translate("SortDialog", "Order:", 0, QApplication::UnicodeUTF8));
        comboBox_6->clear();
        comboBox_6->insertItems(0, QStringList()
         << QApplication::translate("SortDialog", "Ascending", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SortDialog", "Descending", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class SortDialog: public Ui_SortDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SORTDIALOG_H
