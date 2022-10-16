#pragma once

#include <QMainWindow>
#include <QStackedWidget>
#include <QString>
#include <src/chose_type_game_window/chose_type_game_window.h>
#include <src/constants.h>
#include <src/figure/figure.h>
#include <src/game_field_window/game_field_window.h>
#include <src/liderboard_window/liderboard_window.h>
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

  public slots:
    void windows_manager(int window_id);

  private:
    Ui::Game *ui;
    ChoseTypeGameWindow chose_type_game_window;
    GameFieldWindow game_field_window;
    MenuWindow menu_window;
    SettingsWindow settings_window;
    LiderboardWindow liderboard_window;
};
