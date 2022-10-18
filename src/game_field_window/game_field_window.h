#pragma once

#include <QWidget>
#include <src/constants.h>
#include <src/gameboard/gameboard.h>

namespace Ui {
class GameFieldWindow;
}

/*!
 * \brief The GameFieldWindow class
 * Класс наследник класса QT QWidget
 * \param *game_scene
 * Указатель на объект сцены игры (поле).
 */
class GameFieldWindow : public QWidget {
  Q_OBJECT

public:
  /*!
   * \brief GameFieldWindow
   * Конструктор.
   * \param parent
   */
  explicit GameFieldWindow(QWidget *parent = nullptr);
  ~GameFieldWindow();

private:
  /*!
   * \brief end_game
   * Метод вызывается в конце игры, уведомляет игрока,
   * после чего вызывает окно меню.
   */
  void end_game();

signals:
  /*!
   * \brief change_window
   * Сигнал, который показываем менеджеру окон на какое окно
   * нужно перейти.
   * \param on_window
   * Окно на которое нужно переместиться.
   */
  void change_window(int on_window);

  /*!
   * \brief make_new_record
   * Сигнал для добавления новой записи в таблицу лидеров
   */
  void make_new_record(QString);

private slots:
  /*!
   * \brief buttonBackGame_released
   * Слот, обрабатывающий нажатие кнопки.
   * Отправляет сигнал перехода на окно меню.
   */
  void buttonBackGame_released();
  /*!
   * \brief buttonNewGame_released
   * Слот, обрабатывающий нажатие кнопки.
   * Отправляет сигнал перехода на окно игры (перезапускает игру).
   */
  void buttonNewGame_released();
  /*!
   * \brief save_move
   * Метод, сохраняющий произведенные ходы.
   * \param move
   * Запись хода.
   */
  void save_move(QString move);

private:
  Ui::GameFieldWindow *ui;
  GameGraphicScene *game_scene;
};
