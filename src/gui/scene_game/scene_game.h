#pragma once

#include <QGraphicsScene>
#include <QList>
#include <QVector>

/**
 * @brief SceneGame
 * наследник стандартного класса QT - QGraphicsScene.
 * Данный класс используется для отрисовки игрового поля.
 * Он является сценой для QGraphicsWidget.
 */
class SceneGame : public QGraphicsScene {
public:
  /**
   * @brief SceneGame
   * конструктор
   * @param parent
   */
  explicit SceneGame(QObject *parent = nullptr);

signals:
  /**
   * @brief save_move
   * сигнал, отправляющий запись хода, который нужно сохранить.
   * @param move
   * запись хода.
   */
  void save_move(QString move);
  /**
   * @brief moved_figure
   * сигнал, показывающих, какой ход был совершен.
   * @param coords_from
   * координаты ячейки в которой фигура находилась
   * до начала хода.
   * @param coords_to
   * координаты ячейки в которой фигура находится
   * после завершения хода.
   */
  void moved_figure(QPair<int, int> coords_from, QPair<int, int> coords_to);

private slots:
  /**
   * @brief catch_move_figure
   * слот, обрабатывающий перемещение фигур на поле.
   * @todo
   * связать с сигналами QGraphicsItem
   */
  void catch_move_figure();
};
