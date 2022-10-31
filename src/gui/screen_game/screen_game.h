#pragma once

#include "../scene_game/scene_game.h"
#include <QString>
#include <QWidget>
#include <src/constants.h>

namespace Ui {
class ScreenGame;
}

/**
 * @brief The ScreenGame
 * наследник QT QWidget
 * @param *game_scene
 * указатель на объект сцены игры (поле).
 */
class ScreenGame : public QWidget {
  Q_OBJECT

public:
  /**
   * @brief ScreenGame
   * конструктор.
   * @param parent
   */
  explicit ScreenGame(QWidget *parent = nullptr);
  ~ScreenGame();

private:
  /**
   * @brief generateScene
   * метод, который вызывается слотом update, по полученным
   * данным генерирует новую сцену для отрисовки.
   */
  void generateScene(/* Данные */);

signals:
  /**
   * @brief change_window
   * сигнал, который показывает менеджеру окон на какое окно
   * нужно перейти.
   * @param on_window
   * окно на которое нужно переместиться.
   */
  void change_window(int on_window);

public slots:
  /**
   * @brief update
   * слот, который получает данные для отрисовки из логики.
   */
  void update(/* Данные */);

private slots:
  /**
   * @brief buttonBackGame_released
   * слот, обрабатывающий нажатие кнопки.
   * Отправляет сигнал перехода на окно меню.
   */
  void buttonBackGame_released();
  /**
   * @brief buttonNewGame_released
   * слот, обрабатывающий нажатие кнопки.
   * Отправляет сигнал перехода на окно игры (перезапускает игру).
   */
  void buttonNewGame_released();

private:
  Ui::ScreenGame *ui;
  SceneGame scene;
};
