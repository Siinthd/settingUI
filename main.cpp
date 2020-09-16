#include "dialog.h"
#include "mainwindow.h"
#include <QApplication>
#include "settingwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow b;
    Dialog w;
    SettingWindow s;
    b.show();
    w.show();
    s.show();

    return a.exec();
}
