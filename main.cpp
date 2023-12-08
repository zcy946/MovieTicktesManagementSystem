#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //显示框框，利于布局
    qApp->setStyleSheet("QLabel {qproperty-alignment: AlignCenter;}"
                        "QPushButton {font-family: 微软雅黑;}");
    w.show();
    return a.exec();
}
