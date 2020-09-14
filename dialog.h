#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>

class QLineEdit;
class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);

    ~Dialog();

private:
    QLineEdit* m_ptxthostname;
    QLineEdit* m_ptxtusertname;
};
#endif // DIALOG_H
