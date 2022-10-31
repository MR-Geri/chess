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
class MainWindow;
}
QT_END_NAMESPACE

/**
 * @brief Наследник QMainWindow. Этот класс связывает окна игры.
 * @param screen_game
 * окно с полем игры.
 * @param screen_menu
 * окно меню.
 * @param screen_settings
 * окно настроек.
 * @param screen_liderboard
 * окно таблицы лидеров.
 */
class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

public slots:
  /**
   * @brief Менеджер окон, переключает QStacedWidget на тот виджет,
   * номер которого ему передали.
   * @param window_id
   * номер виджета (окна).
   */
  void windowsManager(int window_id);

private:
  Ui::MainWindow *ui;
  ScreenGame screen_game;
  ScreenMenu screen_menu;
  ScreenSettings screen_settings;
  ScreenLiderboard screen_liderboard;
};
