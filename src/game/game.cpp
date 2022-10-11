#include "game.h"
#include "ui_game.h"

Game::Game(QWidget *parent) : QMainWindow(parent), ui(new Ui::Game) {
  ui->setupUi(this);

  ui->stackedWidget->addWidget(&menu_window);
  ui->stackedWidget->addWidget(&settings_window);
  ui->stackedWidget->addWidget(&game_field_window);
  ui->stackedWidget->addWidget(&choose_type_game_window);
  ui->stackedWidget->setCurrentIndex(0);
}

Game::~Game() { delete ui; }
