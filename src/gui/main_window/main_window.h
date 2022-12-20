#pragma once

#include <QMainWindow>
#include <QStackedWidget>
#include <QString>
#include <QVector>
#include <src/constants.h>
#include <src/gui/screen_game/screen_game.h>
#include <src/gui/screen_liderboard/screen_liderboard.h>
#include <src/gui/screen_menu/screen_menu.h>
#include <src/gui/screen_settings/screen_settings.h>
#include <src/logic/engine/engine.h>
#include <src/storage/liderboard/liderboard.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

/**
 * @brief Связывает окна игры.
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

private:
  void sendToGuiBoardData(bool is_new_game = false);

  void endGame(bool);

public slots:
  /**
   * @brief Менеджер окон, переключает QStacedWidget на тот виджет,
   * номер которого ему передали.
   * @param window_id
   * номер виджета (окна).
   */
  void windowsManager(int window_id);

  /**
   * @brief Перемещение и окончание игры.
   *
   * @param from_board позиция откуда
   * @param delta_board шаг
   */
  void connectGuiMoveWithEngine(Position from_board, Position delta_board);

  /**
   * @brief Новая игра.
   */
  void startNewGame();

  /**
   * @brief Обработка нажатия на фигуру.
   *
   * @param position позиция фигуры
   */
  void guiPressFigure(Position position);

  /**
   * @brief Обработка нажатия на фигуру.
   *
   * @param position позиция фигуры
   */
  void guiMousePressFigure(Position position);

signals:
  void sendDataToGui(QVector<QVector<Figures>> data, double advantage_white,
                     bool is_new_game);
  void highlightGuiAttacks(std::list<std::pair<Position, Figures>> attacks);
  void highlightGuiAttacksForMousePress(
      std::list<std::pair<Position, Figures>> attacks);
  void highlightGuiMoves(std::list<std::list<Position>> moves);
  void endParty(Party party);

private:
  Ui::MainWindow *ui;
  Engine engine;
  ScreenGame screen_game;
  ScreenMenu screen_menu;
  ScreenSettings screen_settings;
  ScreenLiderboard screen_liderboard;
  Liderboard storage_liderboard;
};
