#include "game.h"
#include "ui_game.h"

Game::Game(QWidget *parent) : QMainWindow(parent), ui(new Ui::Game) {
  ui->setupUi(this);

  ui->stackedWidget->addWidget(&screen_game);
  ui->stackedWidget->addWidget(&screen_menu);
  ui->stackedWidget->addWidget(&screen_settings);
  ui->stackedWidget->addWidget(&screen_liderboard);
  ui->stackedWidget->setCurrentIndex(Windows::MENU);

  connect(&screen_game, SIGNAL(change_window(int)), this,
          SLOT(windows_manager(int)));
  connect(&screen_menu, SIGNAL(change_window(int)), this,
          SLOT(windows_manager(int)));
  connect(&screen_settings, SIGNAL(change_window(int)), this,
          SLOT(windows_manager(int)));
  connect(&screen_liderboard, SIGNAL(change_window(int)), this,
          SLOT(windows_manager(int)));
}

Game::~Game() { delete ui; }

void Game::windows_manager(int window_id) {
  if (window_id == Windows::EXIT)
    this->close();
  ui->stackedWidget->setCurrentIndex(window_id);
}
