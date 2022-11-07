#include "screen_menu.h"
#include "ui_screen_menu.h"

ScreenMenu::ScreenMenu(QWidget *parent)
    : QWidget(parent), ui(new Ui::ScreenMenu) {
  ui->setupUi(this);

  connect(ui->buttonNewGame, SIGNAL(released()), this, SLOT(goToGameField()));
  connect(ui->buttonLiderboard, SIGNAL(released()), this,
          SLOT(goToLiderboard()));
  connect(ui->buttonSettings, SIGNAL(released()), this, SLOT(goToSettings()));
  connect(ui->buttonExit, SIGNAL(released()), this, SLOT(exit()));
}

ScreenMenu::~ScreenMenu() { delete ui; }

void ScreenMenu::goToSettings() { emit changeWindow(Windows::SETTINGS); }

void ScreenMenu::goToGameField() { emit changeWindow(Windows::GAME_FIELD); }

void ScreenMenu::goToLiderboard() { emit changeWindow(Windows::LIDERBOARD); }

void ScreenMenu::exit() { emit changeWindow(Windows::EXIT); }
