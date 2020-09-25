#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->widget->addAction(QString("Action 1"));
    ui->widget->addAction(QString("Action 2"));
    ui->widget->addAction(QString("Action 3"));
    ui->widget->addAction(QString("Action 4"));
    ui->frame_2->hide();

    QObject::connect(ui->widget, SIGNAL(signal1()), ui->frame, SLOT(show()));
    QObject::connect(ui->widget, SIGNAL(signal2()), ui->frame, SLOT(hide()));

    QObject::connect(ui->widget, SIGNAL(signal1()), ui->frame_2, SLOT(hide()));
    QObject::connect(ui->widget, SIGNAL(signal2()), ui->frame_2, SLOT(show()));
}




MainWindow::~MainWindow() { delete ui; }
