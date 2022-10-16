#include "game_field_window.h"
#include "ui_game_field_window.h"

GameFieldWindow::GameFieldWindow(QWidget *parent)
    : QWidget(parent), ui(new Ui::GameFieldWindow) {
  ui->setupUi(this);

  connect(ui->buttonNewGame, SIGNAL(released()), this,
          SLOT(buttonNewGame_released()));
  connect(ui->buttonBackGame, SIGNAL(released()), this,
          SLOT(buttonBackGame_released()));
}

GameFieldWindow::~GameFieldWindow() { delete ui; }

void GameFieldWindow::buttonNewGame_released() {
  emit change_window(Windows::CHOSE_TYPE_GAME);
}

void GameFieldWindow::buttonBackGame_released() {
  emit change_window(Windows::MENU);
}
