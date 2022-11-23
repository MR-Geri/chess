#pragma once

#include <QGraphicsItem>
#include <QPainter>
#include <QPen>

class GuiAdvantageBar : public QGraphicsItem {
public:
  GuiAdvantageBar(int x_size = 0, int y_size = 0, QColor new_color = Qt::white,
                  QGraphicsItem *parent = nullptr);
  ~GuiAdvantageBar();

  void setAdvantageWhite(float new_advantage_white);

protected:
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
             QWidget *widget = nullptr) override;
  QRectF boundingRect() const override;

private:
  float advantage_white;
  QColor color;
  QRectF bar_rect;
  int x_size;
  int y_size;
};
