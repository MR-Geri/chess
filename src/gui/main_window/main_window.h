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
#include <src/storage/settings/settings.h>

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
  /**
   * @brief Отправляет данные игровой доски на гуи.
   * @param is_new_game показывает началась новая игра или нет.
   */
  void sendToGuiBoardData(bool is_new_game = false);

  /**
   * @brief Завершает игру.
   */
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

  /**
   * @brief Сохраняет громкость музыки при её изменении.
   */
  void connectMusicVolumeToStorage(int);

  /**
   * @brief Сохраняет флаг активности музыки при его изменении.
   */
  void connectMusicFlagToStorage(bool);

  /**
   * @brief Сохраняет громкость музыки при её изменении.
   */
  void connectSoundsVolumeToStorage(int);

  /**
   * @brief Сохраняет флаг активности музыки при его изменении.
   */
  void connectSoundsFlagToStorage(bool);

signals:
  /**
   * @brief Отправляет данные на GUI.
   * @param data матрица фигур.
   * @param advantage_white преимущество белого игрока.
   * @param is_new_game флог новой игры.
   */
  void sendDataToGui(QVector<QVector<Figures>> data, double advantage_white,
                     bool is_new_game);

  /**
   * @brief Отправляет на GUI возможные ходы - атаки.
   * @param attacks список ходов.
   */
  void highlightGuiAttacks(std::list<std::pair<Position, Figures>> attacks);

  /**
   * @brief Отправляе на GUI возможные ходы - атаки, для фигуры которую
   * перемещают.
   * @param attacks список ходов.
   */
  void highlightGuiAttacksForMousePress(
      std::list<std::pair<Position, Figures>> attacks);

  /**
   * @brief Отправляет на GUI возможные ходы - перемещения.
   * @param moves список ходов.
   */
  void highlightGuiMoves(std::list<std::list<Position>> moves);

  /**
   * @brief Издается при завершении игры.
   * @param party итоги партии.
   */
  void endParty(Party party);

private:
  Ui::MainWindow *ui;
  Engine engine;
  ScreenGame screen_game;
  ScreenMenu screen_menu;
  ScreenSettings screen_settings;
  ScreenLiderboard screen_liderboard;
  Liderboard storage_liderboard;
  Settings storage_settings;
};
