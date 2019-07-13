#include <QtGui>
#include "hexspin.h"

HexSpin::HexSpin(QWidget *parent) : QSpinBox(parent)
{
    setRange(0, 255);
    validator = new QRegExpValidator(QRegExp("[0-9A-Fa-f]{1,8}"), this);
}

QValidator::State HexSpin::validate(QString &input, int &pos) const
{
    return validator->validate(input, pos);
}

int HexSpin::valueFromText(const QString &text) const
{
    bool ok;
    return text.toInt(&ok, 16);
}

QString HexSpin::textFromValue(int val) const
{
    return QString::number(val, 16).toUpper();
}





