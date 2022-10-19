#pragma once

#include <QString>
#include <QWidget>
#include <src/constants.h>

namespace Ui {
class GameFieldWindow;
}

/*!
 * \brief The GameFieldWindow class
 * класс наследник класса QT QWidget
 * \param *game_scene
 * указатель на объект сцены игры (поле).
 */
class GameFieldWindow : public QWidget {
  Q_OBJECT

public:
  /*!
   * \brief GameFieldWindow
   * конструктор.
   * \param parent
   */
  explicit GameFieldWindow(QWidget *parent = nullptr);
  ~GameFieldWindow();

private:
  /*!
   * \brief end_game
   * метод вызывается в конце игры, уведомляет игрока,
   * после чего вызывает окно меню.
   */
  void end_game();

signals:
  /*!
   * \brief change_window
   * сигнал, который показывает менеджеру окон на какое окно
   * нужно перейти.
   * \param on_window
   * окно на которое нужно переместиться.
   */
  void change_window(int on_window);

  /*!
   * \brief make_new_record
   * сигнал для добавления новой записи в таблицу лидеров
   */
  void make_new_record(QString record);

private slots:
  /*!
   * \brief buttonBackGame_released
   * слот, обрабатывающий нажатие кнопки.
   * Отправляет сигнал перехода на окно меню.
   */
  void buttonBackGame_released();
  /*!
   * \brief buttonNewGame_released
   * слот, обрабатывающий нажатие кнопки.
   * Отправляет сигнал перехода на окно игры (перезапускает игру).
   */
  void buttonNewGame_released();
  /*!
   * \brief save_move
   * метод, сохраняющий произведенные ходы.
   * \param move
   * Запись хода.
   */
  void save_move(QString move);

private:
  Ui::GameFieldWindow *ui;
};