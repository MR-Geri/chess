#pragma once

#include <QWidget>
#include <src/bot/bot.h>
#include <src/gameboard/gameboard.h>

namespace Ui {
class GameFieldWindow;
}

class GameFieldWindow : public QWidget {
    Q_OBJECT

public:
    explicit GameFieldWindow(QWidget *parent = nullptr);
    ~GameFieldWindow();

private:
    Ui::GameFieldWindow *ui;
    GameBoard game_board;
    Bot bot;
};
