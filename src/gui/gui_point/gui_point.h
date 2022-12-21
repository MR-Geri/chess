#pragma once

#include <QGraphicsObject>
#include <QGraphicsSceneEvent>
#include <QPainter>
#include <src/utils.h>

/**
 * @brief Класс графической точки. Служит для подсветки возможных ходов.
 */
class GuiPoint : public QGraphicsObject {
  Q_OBJECT
public:
  GuiPoint(QGraphicsItem *parent = nullptr);
  GuiPoint(float size_cell, QGraphicsItem *parent = nullptr);

  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
             QWidget *widget = nullptr) override;

  QRectF boundingRect() const override;

protected:
  void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

signals:
  /**
   * @brief Издается при нажатии на точку.
   */
  void press(Position);

private:
  float size_rect;
  float radius;
};
