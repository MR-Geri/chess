#include "game.h"
#include "ui_game.h"

Game::Game(QWidget *parent) : QMainWindow(parent), ui(new Ui::Game) {
  ui->setupUi(this);

  ui->stackedWidget->addWidget(&choose_type_game_window);
  ui->stackedWidget->addWidget(&game_field_window);
  ui->stackedWidget->addWidget(&menu_window);
  ui->stackedWidget->addWidget(&settings_window);
  ui->stackedWidget->addWidget(&liderboard_window);
  ui->stackedWidget->setCurrentIndex(2);
  connect(&menu_window, SIGNAL(change_window(int)), this,
          SLOT(windows_manager(int)));
}

Game::~Game() { delete ui; }

void Game::windows_manager(int window_id) {
  if (window_id == Windows::EXIT)
    this->close();
  ui->stackedWidget->setCurrentIndex(window_id);
}
