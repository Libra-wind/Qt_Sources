#include<QApplication>
#include<QtGui>
#include<QPushButton>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    QWidget w;
    w.resize(200,200);
#if 0
    QPushButton *bt1 = new QPushButton("test1", &w);
    bt1->setGeometry(0,0,80,60);
    bt1->setFlat(true);
    QPushButton *bt2 = new QPushButton("test2", &w);
    bt2->setGeometry(0,70,80,60);
    w.show();
    bt2->setDefault(true);
    qDebug() << bt1->isDefault() << endl;
    qDebug() << bt2->isDefault() << endl;
#endif
    QPushButton *bt1 = new QPushButton("Popup Button", &w);
    QMenu *item =

    return app.exec();
}

