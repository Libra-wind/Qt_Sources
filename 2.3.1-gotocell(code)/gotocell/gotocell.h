#ifndef GOTOCELL_H
#define GOTOCELL_H

#include <QDialog>

class QPushButton;
class QLabel;
class QLineEdit;

class GoToCellDialog : public QDialog
{
    Q_OBJECT
public:
    GoToCellDialog(QWidget* parent = 0);
private:
    QPushButton *okButton;
    QPushButton *cancelButton;
    QLabel *m_label;
    QLineEdit *m_lineEdit;
public slots:
    void SetButtonEnable(const QString &str);
};


#endif // GOTOCELL_H
