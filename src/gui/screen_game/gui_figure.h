#pragma once

#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSvgItem>
#include <QSvgRenderer>
#include <src/constants.h>
#include <src/utils.h>

/**
 * @brief Класс графической фигуры. Используется для отрисовки фигур.
 */
class GuiFigure : public QGraphicsSvgItem {
  Q_OBJECT
public:
  GuiFigure(QGraphicsItem *parent = nullptr);
  GuiFigure(float w_gV, float h_gV, Figures figure,
            QGraphicsItem *parent = nullptr);
  ~GuiFigure();

protected:
  void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
  void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

signals:
  /**
   * @brief Издается при перемещении фигуры.
   * @param from позиция, на которой фигура находилась.
   * @param delta смещение фигуры.
   */
  void moved(Position from, Position delta);

  /**
   * @brief Издается при клике по фигуре без смещения.
   * @param position позиция фигуры.
   */
  void mousePressed(Position position);

  /**
   * @brief Издается при нажатии на фигуру.
   */
  void press(Position);

private:
  float scale;
  QSvgRenderer *renderer;
  Position last_delta_move;
  float x;
  float y;
};
