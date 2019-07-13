#ifndef HEXSPIN_H
#define HEXSPIN_H

#include <QSpinBox>

class QRegExpValidator;

class HexSpin : public QSpinBox
{
    Q_OBJECT
public:
    HexSpin(QWidget* parent = 0);
protected:
    QValidator::State validate(QString &input, int &pos) const;
    int valueFromText(const QString &text) const;
    QString textFromValue(int val) const;
private:
    QRegExpValidator* validator;
};



#endif // HEXSPIN_H
