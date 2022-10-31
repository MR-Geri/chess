#pragma once

#include <QGraphicsScene>
#include <QList>
#include <QVector>

/**
 * @brief Отрисовывает игровое поле.
 */
class SceneGame : public QGraphicsScene {
public:
  explicit SceneGame(QObject *parent = nullptr);

signals:
  /**
   * @brief Сигнал, отправляющий запись хода, который нужно сохранить.
   * @param move
   * ход для записи.
   */
  void saveMove(QString move);
  /**
   * @brief Показывает, какой ход был совершен.
   * @param coords_from
   * координаты ячейки в которой фигура находилась
   * до начала хода.
   * @param coords_to
   * координаты ячейки в которой фигура находится
   * после завершения хода.
   */
  void movedFigure(QPair<int, int> coords_from, QPair<int, int> coords_to);

private slots:
  /**
   * @brief Обрабатывает перемещение фигур на поле.
   * @todo
   * связать с сигналами QGraphicsItem
   */
  void catchMoveFigure();
};
