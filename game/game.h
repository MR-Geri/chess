#pragma once

#include <QMainWindow>
#include <QStackedWidget>
#include <chose_type_game_window.h>
#include <game_field_window.h>
#include <menu_window.h>
#include <settings_window.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Game; }
QT_END_NAMESPACE

class Game : public QMainWindow
{
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
