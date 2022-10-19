#pragma once

#include <QGraphicsScene>
#include <QList>
#include <QVector>

/*!
 * \brief GameGraphicScene
 * наследник стандартного класса QT - QGraphicsScene.
 * Данный класс используется для отрисовки игрового поля.
 * Он является сценой для QGraphicsWidget.
 * \param board объект класса ChessBoard - игровая доска.
 */
class SceneGame : public QGraphicsScene {
public:
  /*!
   * \brief GameGraphicScene
   * конструктор
   * \param parent
   */
  explicit SceneGame(QObject *parent = nullptr);
  /*!
   * \brief move_figure
   * метод, перемещающий фигуры на поле board.
   * \param old_position
   * старая позиция фигуры.
   * \param new_position
   * новая позиция фигуры.
   */
  void move_figure(QPair<int, int> old_position, QPair<int, int> new_position);

  /*!
   * \brief is_end_game
   * метод вызывается после каждого хода для проверки конца игры.
   * Если возможных ходов нет, значит игра завершилась. Вызывается
   * после каждого хода.
   * \return
   * 0 - если игра не завершена
   * 1 - если победили белые
   * -1 - если победили черные
   */
  int is_end_game();

private:
  /*!
   * \brief update_scene
   * метод, обновляющий сцену, вызывается из метода move_figure.
   */
  void update_scene();

signals:
  /*!
   * \brief move_for_save
   * сигнал, отправляющий запись хода, который нужно сохранить.
   * \param move
   * запись хода.
   */
  void move_for_save(QString move);

private slots:
  /*!
   * \brief catch_move_figure
   * слот, обрабатывающий перемещение фигур на поле.
   * \todo
   * связать с сигналами QGraphicsItem
   */
  void catch_move_figure();
};
