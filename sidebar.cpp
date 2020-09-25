#include "sidebar.h"

#include <QDebug>
#include <QEvent>
#include <QPaintEvent>
#include <QPainter>

#define action_height 60

SideBar::SideBar(QWidget *parent)
    : QWidget(parent), checkedAction_(nullptr), overAction_(nullptr) {
  setMouseTracking(true);
}
void SideBar::addAction(QAction *action) {
  mActions_.push_back(action);
  action->setCheckable(true);
}
QAction *SideBar::addAction(const QString &text) {
  QAction *action = new QAction(QIcon(""), text, this);
  action->setCheckable(true);
  mActions_.push_back(action);
  return action;
}
QSize SideBar::minimumSizeInit() const {
  return action_height * QSize(1, mActions_.size());
}

void SideBar::paintEvent(QPaintEvent *event) {
  QPainter p(this);
  QFont fontText(p.font());
  p.setFont(fontText);

  int action_y = 0;
  p.fillRect(rect(), QColor(240, 240, 240));

  for (auto action : mActions_) {

    QRect actionRect(0, action_y, event->rect().width(), action_height);

    if (action->isChecked()) {
      p.fillRect(actionRect, QColor(180, 180, 180));
      p.setPen(QColor(0, 0, 0));
    }

    if (action == overAction_) {
      p.fillRect(actionRect, QColor(220, 220, 220));
    }

    p.setPen(QColor(0, 0, 0));
    QSize size = p.fontMetrics().size(Qt::TextSingleLine, action->text());
    QRect actionTextRect(QPoint(actionRect.width() / 2 - size.width() / 2,
                                actionRect.bottom() - size.height() - 25),
                         size);
    p.drawText(actionTextRect, Qt::AlignCenter, action->text());

    QRect actionIconRect(0, action_y + 10, actionRect.width(),
                         actionRect.height() - 2 * actionTextRect.height() -
                             10);
    QIcon actionIcon(action->icon());
    actionIcon.paint(&p, actionIconRect);

    action_y += actionRect.height();
  }
}

void SideBar::mousePressEvent(QMouseEvent *event) {
  QAction *tempAction = actionAt(event->pos());
  if (tempAction == nullptr || tempAction->isChecked())
    return;
  qDebug() << "clicked";
  if (checkedAction_)
    checkedAction_->setChecked(false);
  if (overAction_ == tempAction)
    overAction_ = nullptr;
  checkedAction_ = tempAction;
  tempAction->setChecked(true);
  showFrame();
  update();
  QWidget::mousePressEvent(event);
}

void SideBar::mouseMoveEvent(QMouseEvent *event) {
  QAction *tempAction = actionAt(event->pos());
  if (tempAction == nullptr) {
    overAction_ = nullptr;
    update();
    return;
  }
  if (tempAction->isChecked() || overAction_ == tempAction)
    return;
  overAction_ = tempAction;
  update();
  QWidget::mouseMoveEvent(event);
}

void SideBar::leaveEvent(QEvent *event) {
  overAction_ = nullptr;
  update();
  QWidget::leaveEvent(event);
}

QAction *SideBar::actionAt(const QPoint &at) {
  int action_y = 0;
  int position = 0;
  for (auto action : mActions_) {
    QRect actionRect(0, action_y, rect().width(), action_height);
    if (actionRect.contains(at)) {
      currentstate = position;
      return action;
    }
    action_y += actionRect.height();
    position++;
  }
  return nullptr;
}

void SideBar::showFrame() {
  switch (currentstate) {
  case 0:
    emit signal1();
    break;
  case 1:
    emit signal2();
    break;
  }
}
