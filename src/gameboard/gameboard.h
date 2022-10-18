#pragma once

#include <QGraphicsScene>
#include <QList>
#include <QVector>

/*!
 * \brief ChessBoard
 *
 * Класс наследник стандартного класса QT - QGraphicsScene.
 * Данный класс используется для отрисовки игрового поля.
 * Он является сценой для QGraphicsWidget.
 *
 * \param map Матрица, которая хранит фигуры и их расположение на поле.
 */

class ChessBoard {
public:
  /*!
   * \brief ChessBoard
   * Коструктор по умолчанию, генерирует поле с фигурами
   * (стартовая расстановка и набор фигур).
   */
  ChessBoard();
  /*!
   * \brief get_possible_steps_from
   * Константный метод, возвращающий список ходов, которые может совершить
   * фигура, находящаяся на поле в ячейке с координатами coords. \param coords
   * Координаты фигуры для которой необходимо получить возможные ходы.
   * \return
   * Список возможных ходов для фигуры с координатами
   * coords.
   */
  QList<QPair<int, int>> get_possible_steps_from(QPair<int, int> coords) const;
  /*!
   * \brief get_figure_from
   * Константный метод, возвращающий тип фигуры, которая находится в
   * ячейке поля с координатами coords.
   * \param coords
   * Координаты ячейки поля, содержимое которой нужно узнать.
   * \return
   * Значение int, которое может принимать целочисленные значения
   * от -5 до 5 включительно.
   */
  int get_figure_from(QPair<int, int> coords) const;
  /*!
   * \private
   * \brief get_situation
   * Константный метод, возвращающий текущую ситуацию на поле.
   * \warning
   * Пока нигде не планируется изпользоваться.
   * \return
   * Значение int, которое может принимать значения от -100 до 100,
   * где -100 означает победу черных, а 100 означает победу белых.
   */
  int get_situation() const;

private:
  QVector<QVector<int>> map;
};

/*!
 * \brief GameBoard
 *
 * Класс наследник стандартного класса QT - QGraphicsScene.
 * Данный класс используется для отрисовки игрового поля.
 * Он является сценой для QGraphicsWidget.
 *
 * \param board Объект класса ChessBoard - игровая доска.
 */

class GameGraphicScene : public QGraphicsScene {
public:
  /*!
   * \brief GameGraphicScene
   * Конструктор
   * \param parent
   */
  explicit GameGraphicScene(QObject *parent = nullptr);

  /*!
   * \brief move_figure
   * Метод, перемещающий фигуры на поле board.
   * \param old_position
   * Старая позиция фигуры.
   * \param new_position
   * Новая позиция фигуры.
   */
  void move_figure(QPair<int, int> old_position, QPair<int, int> new_position);

private:
  /*!
   * \brief update_scene
   * Метод, обновляющий сцену, вызывается из метода move_figure.
   */
  void update_scene();

private slots:
  /*!
   * \brief catch_move_figure
   * Слот, обрабатывающий перемещение фигур на поле.
   * \todo
   * Связать с сигналами QGraphicsItem
   */
  void catch_move_figure();

private:
  ChessBoard board;
};
