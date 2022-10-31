#include "screen_menu.h"
#include "ui_screen_menu.h"

ScreenMenu::ScreenMenu(QWidget *parent)
    : QWidget(parent), ui(new Ui::ScreenMenu) {
  ui->setupUi(this);

  connect(ui->buttonNewGame, SIGNAL(released()), this,
          SLOT(go_to_game_field()));
  connect(ui->buttonLiderboard, SIGNAL(released()), this,
          SLOT(go_to_liderboard()));
  connect(ui->buttonSettings, SIGNAL(released()), this, SLOT(go_to_settings()));
  connect(ui->buttonExit, SIGNAL(released()), this, SLOT(exit()));
}

ScreenMenu::~ScreenMenu() { delete ui; }

void ScreenMenu::goToSettings() { emit changeWindow(Windows::SETTINGS); }

void ScreenMenu::goToGameField() { emit changeWindow(Windows::GAME_FIELD); }

void ScreenMenu::goToLiderboard() { emit changeWindow(Windows::LIDERBOARD); }

void ScreenMenu::exit() { emit changeWindow(Windows::EXIT); }
