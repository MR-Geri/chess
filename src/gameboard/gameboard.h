#pragma once

#include <QGraphicsScene>
#include <QList>
#include <QVector>

/*!
 * \brief ChessBoard
 * класс наследник стандартного класса QT - QGraphicsScene.
 * Данный класс используется для отрисовки игрового поля.
 * Он является сценой для QGraphicsWidget.
 * \param map матрица, которая хранит фигуры и их расположение на поле.
 */
class ChessBoard {
public:
  /*!
   * \brief ChessBoard
   * коструктор по умолчанию, генерирует поле с фигурами
   * (стартовая расстановка и набор фигур).
   */
  ChessBoard();
  /*!
   * \brief get_possible_steps_from
   * константный метод, возвращающий список ходов, которые может совершить
   * фигура, находящаяся на поле в ячейке с координатами coords.
   * \param coords
   * координаты фигуры для которой необходимо получить возможные ходы.
   * \return
   * список возможных ходов для фигуры с координатами
   * coords.
   */
  QList<QPair<int, int>> get_possible_steps_from(QPair<int, int> coords) const;
  /*!
   * \brief get_figure_from
   * константный метод, возвращающий тип фигуры, которая находится в
   * ячейке поля с координатами coords.
   * \param coords
   * координаты ячейки поля, содержимое которой нужно узнать.
   * \return
   * значение int, которое может принимать целочисленные значения
   * от -5 до 5 включительно.
   */
  int get_figure_from(QPair<int, int> coords) const;
  /*!
   * \private
   * \brief get_situation
   * константный метод, возвращающий текущую ситуацию на поле.
   * \warning
   * пока нигде не планируется изпользоваться.
   * \return
   * значение int, которое может принимать значения от -100 до 100,
   * где -100 означает победу черных, а 100 означает победу белых.
   */
  int get_situation() const;

private:
  QVector<QVector<int>> map;
};

/*!
 * \brief GameBoard
 * наследник стандартного класса QT - QGraphicsScene.
 * Данный класс используется для отрисовки игрового поля.
 * Он является сценой для QGraphicsWidget.
 * \param board объект класса ChessBoard - игровая доска.
 */
class GameGraphicScene : public QGraphicsScene {
public:
  /*!
   * \brief GameGraphicScene
   * конструктор
   * \param parent
   */
  explicit GameGraphicScene(QObject *parent = nullptr);
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

private:
  ChessBoard board;
};
