#include "mainwindow.h"
#include <QApplication>
#include "login.h"
#include "check.h"
#include "link.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    login login;
    //窗口展示函数
    login.show();
    return a.exec();
}
