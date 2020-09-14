#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent,Qt::WindowTitleHint|Qt::WindowSystemMenuHint)
{
    m_ptxthostname = new QLineEdit;
    m_ptxtusertname = new QLineEdit;

    QLabel* plblhostname   = new QLabel("&Hostname");
    QLabel* plbluserName     = new QLabel("&Username");


    plblhostname->setBuddy(m_ptxthostname);
    plbluserName->setBuddy(m_ptxtusertname);

    QPushButton* pcmdOk     = new QPushButton("&Ok");
    QPushButton* pcmdCancel = new QPushButton("&Cancel");

    connect(pcmdOk, SIGNAL(clicked()), SLOT(accept()));
    connect(pcmdCancel, SIGNAL(clicked()), SLOT(reject()));

    QGridLayout* ptopLayout = new QGridLayout;
    ptopLayout->addWidget(plblhostname, 0, 0);
    ptopLayout->addWidget(plbluserName, 1, 0);
    ptopLayout->addWidget(m_ptxthostname, 0, 1);
    ptopLayout->addWidget(m_ptxtusertname, 1, 1);
    ptopLayout->addWidget(pcmdOk, 2,0);
    ptopLayout->addWidget(pcmdCancel, 2, 1);
    setLayout(ptopLayout);
}

Dialog::~Dialog()
{

}

