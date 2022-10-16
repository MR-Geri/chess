#include "chose_type_game_window.h"
#include "ui_chose_type_game_window.h"

ChoseTypeGameWindow::ChoseTypeGameWindow(QWidget *parent)
    : QWidget(parent), ui(new Ui::ChoseTypeGameWindow) {
  ui->setupUi(this);

  connect(ui->buttonDualGame_2, SIGNAL(released()), this,
          SLOT(buttonDualGame_2_released()));
  connect(ui->buttonJuniorGame_2, SIGNAL(released()), this,
          SLOT(buttonJuniorGame_2_released()));
  connect(ui->buttonMiddleGame_2, SIGNAL(released()), this,
          SLOT(buttonMiddleGame_2_released()));
  connect(ui->buttonSeniorGame_2, SIGNAL(released()), this,
          SLOT(buttonSeniorGame_2_released()));
}

ChoseTypeGameWindow::~ChoseTypeGameWindow() { delete ui; }

void ChoseTypeGameWindow::buttonDualGame_2_released() {
  emit change_window(Windows::GAME_FIELD);
}

void ChoseTypeGameWindow::buttonJuniorGame_2_released() {
  emit change_window(Windows::GAME_FIELD);
}

void ChoseTypeGameWindow::buttonMiddleGame_2_released() {
  emit change_window(Windows::GAME_FIELD);
}

void ChoseTypeGameWindow::buttonSeniorGame_2_released() {
  emit change_window(Windows::GAME_FIELD);
}
