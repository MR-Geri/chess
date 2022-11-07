#include "screen_game.h"
#include "ui_screen_game.h"

ScreenGame::ScreenGame(QWidget *parent)
    : QWidget(parent), ui(new Ui::ScreenGame) {
  ui->setupUi(this);

  connect(ui->buttonNewGame, SIGNAL(released()), this,
          SLOT(buttonNewGameReleased()));
  connect(ui->buttonBackGame, SIGNAL(released()), this,
          SLOT(buttonBackGameReleased()));
}

ScreenGame::~ScreenGame() { delete ui; }

void ScreenGame::buttonNewGameReleased() {}

void ScreenGame::buttonBackGameReleased() { emit changeWindow(Windows::MENU); }

void ScreenGame::update() {}

void ScreenGame::generateScene() {}
