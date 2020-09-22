#ifndef SIDEBAR_H
#define SIDEBAR_H

#include <QWidget>
#include <QAction>

namespace Ui {
class SideBar;
}

class SideBar : public QWidget
{
    Q_OBJECT

public:
    explicit SideBar(QWidget *parent = nullptr);
    void addAction(QAction *action);
    QAction *addAction(const QString &text);
    QSize minimumSizeInit() const;
    int position(){return currentstate;}

protected:
  void paintEvent(QPaintEvent *event);
  void mousePressEvent(QMouseEvent *event);
  void mouseMoveEvent(QMouseEvent *event);
  void leaveEvent(QEvent *event);
  QAction *actionAt(const QPoint &at);
  void showFrame();

signals:
  void signal1();
  void signal2();

private:
    QList<QAction*> mActions_;
    int currentstate = 0;
    QAction *checkedAction_;
    QAction *overAction_;
};

#endif // SIDEBAR_H
