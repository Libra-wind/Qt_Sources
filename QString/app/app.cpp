/**
  ******************************************************************************
  * @file    app.cpp
  * @author  Wind
  * @version
  * @date
  * @brief   the using ways about class QString
  ******************************************************************************
*/
#include<QApplication>
#include<QTextCodec>
#include<QStringList>
#include<QDebug>
int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    //设置tr函数的编码：uft8
    //QTextCodec::setCodecForTr(QTextCodec::codecForName("utf8"));
    qDebug() << QObject::trUtf8("以下是编辑字符串的操作：");
    QString str = "hello";
    //size函数返回字符串大小
    qDebug() << QObject::trUtf8("字符串大小：") << str.size();
    //append函数会在后面插入内容
    qDebug() << str.append(" Qt");
    QString str1 = "%1-%2";
    //arg函数，可以替换掉字符串内的%1,%2...%100
    qDebug() << str1.arg("Hello Qt", "By Wind");//.arg("By Wind");
    qDebug() << QString("Processing file %1 of %2:%3").arg(1).arg(2).arg("sss.csv");
    //在某个位置插入字符/字符串
    qDebug() << str.insert(6, "my ");
    qDebug() << str.replace(1,4, 'i');
    str = str + "!!!";
    qDebug() << str;
    qDebug() << QObject::tr("******************Second Part*******************");
    str = "hi\r\nQt!\n";
    qDebug() << str << QObject::trUtf8("字符串大小：") << str.size();
    //trimmed函数只清除字符串两端的空白字符，如\r, \n, \t;
    //simplified函数会清除两端的空白字符，还会给中间的空白字符替换为空格
    QString str2 = str.trimmed();
    qDebug() << "str2 = " << str2 << QObject::trUtf8("字符串大小：") << str2.size();
    QString str3 = str.simplified();
    qDebug() << "str3 = " << str3 << QObject::trUtf8("字符串大小：") << str3.size();

    qDebug() << QObject::tr("******************Third Part*******************");
    str = "hi,my,,Qt";
    QStringList strList = str.split(",", QString::SkipEmptyParts);
    //获得QStringList的数量
    qDebug() << strList.count();
    //通过数组访问List的内容
    qDebug() << strList[0] << strList[1] << strList[2];

    return app.exec();
}

