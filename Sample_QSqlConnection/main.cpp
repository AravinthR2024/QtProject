#include "mainwindow.h"
#include <QApplication>

#include <QFile>
#include <QTextStream>

#include <stdio.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QString strThemeFileName;

#if 0
    if (!fileConfig.open (QIODevice::WriteOnly))
    {
        qDebug("Config File loading Error");
    }
    QDataStream stream(&fileConfig);
    stream << QString("this is the answer");
    fileConfig.close ();
#endif

    QFile fileConfig("./config/config.bin");

    if (!fileConfig.open(QIODevice::ReadOnly))
    {
        qDebug("Config File loading Error");
    }

    QDataStream stream;
    stream.setDevice (&fileConfig);
    stream >> strThemeFileName;
    fileConfig.close ();

//    QFile styleFile(strThemeFileName);
//    styleFile.open (QIODevice::ReadOnly);
//    QTextStream styleTextStream (&styleFile);
//    QString styleText = styleTextStream.readAll ();
//    if (styleText == ":/qss/qss/lightmode.css")
//    {
//        ((MainWindow*)this->parent ())->c
//    }
    if (strThemeFileName == "dark")
    {
        w.changeThemeState (false);
    }
    else if (strThemeFileName == "light")
    {
        w.changeThemeState (true);
    }
    else
    {
        qDebug("Theme file missing or misplaced");
    }
//    w.setStyleSheet (styleText.toStdString ().c_str ());
    w.show();

    return a.exec();
}
