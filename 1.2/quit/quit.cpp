#include <QApplication>
#include <QPushButton>


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    QPushButton *bt = new QPushButton("Quit");

    QObject::connect(bt, SIGNAL(clicked()), &app, SLOT(quit()));
    bt->show();
    return app.exec();


}
