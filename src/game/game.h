#pragma once

#include <QMainWindow>
#include <QStackedWidget>
#include <QString>
#include <src/constants.h>
#include <src/gui/screen_game/screen_game.h>
#include <src/gui/screen_liderboard/screen_liderboard.h>
#include <src/gui/screen_menu/screen_menu.h>
#include <src/gui/screen_settings/screen_settings.h>

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
  ScreenGame screen_game;
  ScreenMenu screen_menu;
  ScreenSettings screen_settings;
  ScreenLiderboard screen_liderboard;
};
