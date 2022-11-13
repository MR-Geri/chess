#pragma once

#include <QGraphicsScene>
#include <QGraphicsSvgItem>
#include <QString>
#include <QWidget>
#include <src/constants.h>
#include <src/gui/screen_game/gui_figure.h>

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
  void catchData(QVector<QVector<Figures>> catched_data);

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
  void resizeEvent(QResizeEvent *event);
  void drawGameField();

private:
  Ui::ScreenGame *ui;
  QGraphicsScene *scene;
  QGraphicsSvgItem *board;
  QVector<QVector<Position>> positions;
  QVector<QVector<Figures>> data;
};
