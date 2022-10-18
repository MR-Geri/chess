#pragma once

#include <QWidget>
#include <src/constants.h>
#include <src/gameboard/gameboard.h>

namespace Ui {
class GameFieldWindow;
}

class GameFieldWindow : public QWidget {
  Q_OBJECT

public:
  explicit GameFieldWindow(QWidget *parent = nullptr);
  ~GameFieldWindow();

signals:
  void change_window(int on_window);

private slots:
  void buttonBackGame_released();
  void buttonNewGame_released();

private:
  Ui::GameFieldWindow *ui;
  GameGraphicScene game_scene;
  int game_type;
};
