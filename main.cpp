#include "mainwindow.h"

#include <QApplication>
#include <QFile>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    // QFile styleFile(":/style/stylesheets.qss");
    // if(styleFile.open(QFile::ReadOnly | QFile::Text)) {
    //     QTextStream stream(&styleFile);
    //     a.setStyleSheet(stream.readAll());
    //     styleFile.close();
    // } else {
    //     qWarning("无法加载样式表文件！");
    // }
    return a.exec();
}
