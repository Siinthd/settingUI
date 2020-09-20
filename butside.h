#ifndef BUTSIDE_H
#define BUTSIDE_H

#include <QWidget>

namespace Ui {
class butside;
}

class butside : public QWidget
{
    Q_OBJECT

public:
    explicit butside(QWidget *parent = nullptr);
    ~butside();

private:
    Ui::butside *ui;
};

#endif // BUTSIDE_H
