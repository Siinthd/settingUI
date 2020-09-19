#include "settingwindow.h"
#include "ui_settingwindow.h"

SettingWindow::SettingWindow(QWidget *parent)
    : QDialog(parent), ui(new Ui::SettingWindow) {
    ui->setupUi(this);

    // placeholders
    ui->Port->setPlaceholderText(
        QString::fromStdString(settings.getPortname()));
    ui->IpAddress->setPlaceholderText(
        QString::fromStdString(settings.getHostname()));
    ui->Usename_edit->setPlaceholderText(
        QString::fromStdString(settings.getUsername()));

    // buttons connecting
    QObject::connect(ui->OKbutton, &QPushButton::clicked, [this]() {
        settings.WriteSettings();
        close();
    });

    QObject::connect(ui->CnclButton, SIGNAL(clicked()), this, SLOT(reject()));

    QObject::connect(ui->defaultButton, &QPushButton::clicked, [this]() {
        settings.SetDefaultSettings();
        ui->Port->setText(QString::fromStdString(settings.getPortname()));
        ui->IpAddress->setText(QString::fromStdString(settings.getHostname()));
        ui->Usename_edit->setText(
            QString::fromStdString(settings.getUsername()));
    });

    QObject::connect(
        ui->IpAddress, &QLineEdit::textChanged,
        [this](const QString &Text) { settings.setHostname(Text); });

    QObject::connect(
        ui->Port, &QLineEdit::textChanged,
        [this](const QString &Text) { settings.setPortname(Text); });

    QObject::connect(
        ui->Usename_edit, &QLineEdit::textChanged,
        [this](const QString &Text) { settings.setUsername(Text); });
}

SettingWindow::~SettingWindow() { delete ui; }
