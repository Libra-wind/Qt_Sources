#include <QApplication>
#include "hexspin.h"
#include <QWidget>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    QWidget w;

    HexSpin *spin = new HexSpin(&w);

    w.show();

    return app.exec();
}

