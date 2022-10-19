#pragma once

#include <QMainWindow>
#include <QStackedWidget>
#include <QString>
#include <src/constants.h>
#include <src/gui/game_field_window/game_field_window.h>
#include <src/gui/liderboard_window/liderboard_window.h>
#include <src/gui/menu_window/menu_window.h>
#include <src/gui/settings_window/settings_window.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class Game;
}
QT_END_NAMESPACE

/*!
 * \brief The Game class
 * класс наследник класса QT QMainWindow. Главный класс игры.
 * Этот класс связывает окна игры.
 * \param GameFieldWindow
 * окно с полем игры.
 * \param MenuWindow
 * окно меню.
 * \param SettingsWindow
 * окно настроек.
 * \param LiderboardWindow
 * окно таблицы лидеров.
 */
class Game : public QMainWindow {
  Q_OBJECT

public:
  /*!
   * \brief Game
   * конструктор.
   * \param parent
   */
  Game(QWidget *parent = nullptr);
  ~Game();

public slots:
  /*!
   * \brief windows_manager
   * менеджер окон, переключает QStacedWidget на тот виджет,
   * номер которого ему передали.
   * \param window_id
   * номер виджета (окна).
   */
  void windows_manager(int window_id);

private:
  Ui::Game *ui;
  GameFieldWindow game_field_window;
  MenuWindow menu_window;
  SettingsWindow settings_window;
  LiderboardWindow liderboard_window;
};
