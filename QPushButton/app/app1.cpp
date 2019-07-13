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
//下拉菜单式按钮
    QPushButton *bt1 = new QPushButton("Popup Button", &w);
    QMenu *item = new QMenu();


    QAction *first = new QAction("&First item", item);
    QAction *second = new QAction("&Second item", item);
    QAction *third = new QAction("&Third item", item);
    QAction *fourth = new QAction("&Fourth item", item);
    item->addAction(first);
    item->addAction(second);
    item->addAction(third);
    item->addAction(fourth);


    bt1->setMenu(item);
#endif
    QPushButton *bt1 = new QPushButton("autodefault", &w);
    bt1->setAutoDefault(true);
    bt1->setGeometry(100,0,80,60);
    QObject::connect(bt1, SIGNAL(clicked(bool)), &w, SLOT(close()));
    QPushButton *bt2 = new QPushButton("autodefault", &w);
    bt2->setDefault(true);
    w.show();
    return app.exec();
}

