
#include <QApplication>
#include "settingwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);



    SettingWindow c;
    c.show();
    return a.exec();
}
