#include "screen_game.h"
#include "ui_screen_game.h"

ScreenGame::ScreenGame(QWidget *parent)
    : QWidget(parent), ui(new Ui::ScreenGame) {
  ui->setupUi(this);

  connect(ui->buttonNewGame, SIGNAL(released()), this,
          SLOT(buttonNewGame_released()));
  connect(ui->buttonBackGame, SIGNAL(released()), this,
          SLOT(buttonBackGame_released()));
}

ScreenGame::~ScreenGame() { delete ui; }

void ScreenGame::buttonNewGame_released() {}

void ScreenGame::buttonBackGame_released() {
  emit change_window(Windows::MENU);
}

void ScreenGame::update() {}

void ScreenGame::generateScene() {}
