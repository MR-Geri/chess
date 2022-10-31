#pragma once

#include "../scene_game/scene_game.h"
#include <QString>
#include <QWidget>
#include <src/constants.h>

namespace Ui {
class ScreenGame;
}

/**
 * @brief Окно игры.
 * @param *game_scene
 * указатель на объект сцены игры (поле).
 */
class ScreenGame : public QWidget {
  Q_OBJECT

public:
  explicit ScreenGame(QWidget *parent = nullptr);
  ~ScreenGame();

private:
  /**
   * @brief Вызывается слотом update, по полученным
   * данным генерирует новую сцену для отрисовки.
   */
  void generateScene(/* Данные */);

signals:
  /**
   * @brief Показывает менеджеру окон на какое окно нужно перейти.
   * @param on_window
   * окно на которое нужно переместиться.
   */
  void changeWindow(int on_window);

public slots:
  /**
   * @brief Получает данные для отрисовки из логики.
   */
  void update(/* Данные */);

private slots:
  /**
   * @brief Отправляет сигнал перехода на окно меню.
   */
  void buttonBackGameReleased();
  /**
   * @brief Отправляет сигнал перехода на окно игры (перезапускает игру).
   */
  void buttonNewGameReleased();

private:
  Ui::ScreenGame *ui;
  SceneGame scene;
};
