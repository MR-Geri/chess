#pragma once

#include <QMainWindow>
#include <QStackedWidget>
#include <QString>
#include <src/constants.h>
#include <src/game_field_window/game_field_window.h>
#include <src/liderboard_window/liderboard_window.h>
#include <src/menu_window/menu_window.h>
#include <src/settings_window/settings_window.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class Game;
}
QT_END_NAMESPACE

/*!
 * \brief The Game class
 * Класс наследник класса QT QMainWindow. Главный класс игры.
 * Этот класс связывает окна игры.
 * \param GameFieldWindow
 * Окно с полем игры.
 * \param MenuWindow
 * Окно меню.
 * \param SettingsWindow
 * Окно настроек.
 * \param LiderboardWindow
 * Окно таблицы лидеров.
 */
class Game : public QMainWindow {
  Q_OBJECT

public:
  /*!
   * \brief Game
   * Конструктор.
   * \param parent
   */
  Game(QWidget *parent = nullptr);
  ~Game();

public slots:
  /*!
   * \brief windows_manager
   * Менеджер окон, переключает QStacedWidget на тот виджет,
   * номер которого ему передали.
   * \param window_id
   * Номер виджета (окна).
   */
  void windows_manager(int window_id);

private:
  Ui::Game *ui;
  GameFieldWindow game_field_window;
  MenuWindow menu_window;
  SettingsWindow settings_window;
  LiderboardWindow liderboard_window;
};
