#include "gui_advantage_bar.h"

GuiAdvantageBar::GuiAdvantageBar(int new_x_size, int new_y_size,
                                 QColor new_color, QGraphicsItem *parent)
    : QGraphicsItem(parent), x_size(new_x_size), y_size(new_y_size) {
  advantage_white = 0.5;
  color = new_color;
  bar_rect = QRectF(0, 0, new_x_size, new_y_size);
}

GuiAdvantageBar::~GuiAdvantageBar() {}

void GuiAdvantageBar::paint(QPainter *painter,
                            const QStyleOptionGraphicsItem *option,
                            QWidget *widget) {
  painter->setPen(QPen(Qt::gray, 1));
  painter->setBrush(QBrush(color));
  painter->drawRect(boundingRect());
}

QRectF GuiAdvantageBar::boundingRect() const { return bar_rect; }

void GuiAdvantageBar::setAdvantageWhite(float new_advantage_white) {
  advantage_white = new_advantage_white;
  bar_rect =
      QRectF(0, 0, x_size, static_cast<int>(y_size * new_advantage_white));
}
