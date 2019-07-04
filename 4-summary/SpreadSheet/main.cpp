#include <QApplication>
#include "mainwindow.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    MainWindow *w = new MainWindow();
    w->setWindowState(Qt::WindowMaximized);
    w->show();

    return app.exec();
}

