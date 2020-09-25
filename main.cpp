#include "mainwindow.h"
#include <QApplication>
#include "settingwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   // SettingWindow c;
    MainWindow win;
    win.show();
    //c.show();
    return a.exec();
}
