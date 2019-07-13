#include<QApplication>
#include<QRegExp>
#include<QDebug>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    //匹配两位数字
    QRegExp rx("^[0-9]{1,2}$");
    qDebug() << rx.indexIn("99");
    //QRegExp rx1("^\\d\\d$");
    rx.setPattern("^\\d\\d$");
    qDebug() << rx.indexIn("99");

    //匹配单词mail或者letter
    rx.setPattern("\\b(mail|letter)\\b");
    rx.indexIn("my email letter");


    //统计letter出现的次数
    QString str = "my letter email letter!";
    int pos = 0;
    int count = 0;

    do
    {
        pos = rx.indexIn(str, pos);
        if(pos >= 0)
        {
            count++;
            pos++;
        }
    }while(pos >= 0);
    qDebug() << count ;

    QString str1 = "M is a M";
    rx.setPattern("\\bM\\b");
    qDebug() << str1.replace(rx, "Mail");

    str1 = "Hi\r\nQt\n";
    rx.setPattern("\\s");
    qDebug() << QObject::trUtf8("字符原型") <<str1 ;
    qDebug() << str1.replace(rx, " ");
    return app.exec();
}

