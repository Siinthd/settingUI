#include "butside.h"
#include "ui_butside.h"

butside::butside(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::butside)
{
    ui->setupUi(this);
}

butside::~butside()
{
    delete ui;
}
