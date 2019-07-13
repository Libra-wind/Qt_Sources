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
#if 0
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
#endif

#if 0
    qDebug() << QObject::trUtf8("以下是在字符串中进行查询的操作");
    QString str4 = "yafeilinux";
    qDebug() << QObject::trUtf8("字符串为：") << str4;
    //以0开始
    qDebug() << str4.right(5);
    qDebug() << str4.left(5);
    //子字符串出现的位置
    qDebug() << str4.indexOf("fei");
    //字符串的首个位置
    qDebug() << str4.at(0);
    //是否包含子字符串
    qDebug() << str4.contains("lin");
    //记录某个字符的出现次数
    qDebug() << str4.count('i');
#endif
#if 0
    qDebug() << QObject::trUtf8("以下是字符串的转换操作：") << endl;
    /*
     * toInt函数：字符串to整形变量
     * number函数:整形变量to字符串
     */
    QString str5 = "100";
    qDebug() << str5.mid(0,2);
    //字符串to整形变量
    qDebug() << str5.toInt();
    int num = 45;
    //整形变量to字符串
    qDebug() << QString::number(num);
    str5 = "FF";
    bool ok;
    //转成十六进制
    int hex = str5.toInt(&ok, 16);
    qDebug() << hex;
    num = 26;
    qDebug() << QString::number(num,16);
    str5 = "123.456";
    qDebug() << str5.toDouble();
    str5 = "abc";
    qDebug() << str5.toUpper();
    str5 = "ABC";
    qDebug() << str5.toLower();
    double value = 123.456;
    qDebug() << QString("%1").arg(value,4,'f',2);
#endif
    QString str = "FF";
    bool ok;
    qDebug() << str.toInt(&ok, 16);
    int num = 26;
    qDebug() << QString::number(num, 16).toUpper();
    return app.exec();
}

