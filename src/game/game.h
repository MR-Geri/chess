#pragma once

#include <QMainWindow>
#include <QStackedWidget>
#include <src/figure/figure.h>
#include <src/chose_type_game_window/chose_type_game_window.h>
#include <src/game_field_window/game_field_window.h>
#include <src/menu_window/menu_window.h>
#include <src/settings_window/settings_window.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Game; }
QT_END_NAMESPACE

class Game : public QMainWindow {
    Q_OBJECT

public:
    Game(QWidget *parent = nullptr);
    ~Game();

private:
    Ui::Game *ui;
    ChoseTypeGameWindow choose_type_game_window;
    GameFieldWindow game_field_window;
    MenuWindow menu_window;
    SettingsWindow settings_window;
};
