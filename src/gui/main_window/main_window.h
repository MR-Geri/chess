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

/*!
 * \brief The MainWindow
 * класс наследникQT QMainWindow. Главный класс игры.
 * Этот класс связывает окна игры.
 * \param ScreenGame
 * окно с полем игры.
 * \param ScreenMenu
 * окно меню.
 * \param ScreenSettings
 * окно настроек.
 * \param ScreenLiderboard
 * окно таблицы лидеров.
 */
class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  /*!
   * \brief MainWindow
   * конструктор.
   * \param parent
   */
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

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
  Ui::MainWindow *ui;
  ScreenGame screen_game;
  ScreenMenu screen_menu;
  ScreenSettings screen_settings;
  ScreenLiderboard screen_liderboard;
};
