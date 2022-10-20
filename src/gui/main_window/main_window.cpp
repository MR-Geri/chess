#include "main_window.h"
#include "ui_main_window.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
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

MainWindow::~MainWindow() { delete ui; }

void MainWindow::windows_manager(int window_id) {
  if (window_id == Windows::EXIT)
    this->close();
  ui->stackedWidget->setCurrentIndex(window_id);
}
