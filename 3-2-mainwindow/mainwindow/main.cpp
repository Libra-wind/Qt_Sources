#include <QApplication>
#include <QTextCodec>
#include "mainwindow.h"


int main(int argc, char* argv[])
{

    QApplication app(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF8"));
    MainWindow *w = new MainWindow;
    w->show();


    return app.exec();
}

