#include <QApplication>
#include "finddialog.h"


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    FindDialog finddialog;
    finddialog.show();

    return app.exec();
}

