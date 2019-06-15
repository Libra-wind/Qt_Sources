//Qt应用程序的头文件
#include <QApplication>
//Qt窗口类头文件
#include <QDialog>
//Qt标签类头文件
#include <QLabel>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    QLabel *label = new QLabel("HelloWorld");
    label->show();


    return app.exec();
}
