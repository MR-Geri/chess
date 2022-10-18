#include "menu_window.h"
#include "ui_menu_window.h"

MenuWindow::MenuWindow(QWidget *parent)
    : QWidget(parent), ui(new Ui::MenuWindow) {
  ui->setupUi(this);

  connect(ui->buttonNewGame, SIGNAL(released()), this,
          SLOT(go_to_game_field()));
  connect(ui->buttonLiderboard, SIGNAL(released()), this,
          SLOT(go_to_liderboard()));
  connect(ui->buttonSettings, SIGNAL(released()), this, SLOT(go_to_settings()));
  connect(ui->buttonExit, SIGNAL(released()), this, SLOT(exit()));
}

MenuWindow::~MenuWindow() { delete ui; }

void MenuWindow::go_to_settings() { emit change_window(Windows::SETTINGS); }

void MenuWindow::go_to_game_field() { emit change_window(Windows::GAME_FIELD); }

void MenuWindow::go_to_liderboard() { emit change_window(Windows::LIDERBOARD); }

void MenuWindow::exit() { emit change_window(Windows::EXIT); }
