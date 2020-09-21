#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->widget->addAction(QString("Action %1").arg(0));
    ui->widget->addAction(QString("Action %2").arg(1));
    ui->widget->addAction(QString("Action %3").arg(2));
}

MainWindow::~MainWindow()
{
    delete ui;
}
