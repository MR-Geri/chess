#include "gui_advantage_bar.h"

GuiAdvantageBar::GuiAdvantageBar(int x_size, int y_size, QGraphicsItem *parent) : QGraphicsItem(parent) {
  advantage_white = 0.5;
  color = Qt::green;
  bar_rect = QRectF(0, 0, x_size, y_size);
}

GuiAdvantageBar::~GuiAdvantageBar() {

}

void GuiAdvantageBar::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
  painter->setPen(QPen(color, 1));
  painter->drawRect(boundingRect());
}

QRectF GuiAdvantageBar::boundingRect() const {
  return bar_rect;
}

void GuiAdvantageBar::setAdvantageWhite(float new_advantage_white) {
  advantage_white = new_advantage_white;
}
