#ifndef SETTINGWINDOW_H
#define SETTINGWINDOW_H
#include <QDialog>
#include "settings.h"

namespace Ui {
class SettingWindow;
}

class SettingWindow : public QDialog {
    Q_OBJECT
    settingutil settings;

   public:
    explicit SettingWindow(QWidget *parent = nullptr);
    ~SettingWindow();

   private:
    Ui::SettingWindow *ui;
};

#endif  // SETTINGWINDOW_H
