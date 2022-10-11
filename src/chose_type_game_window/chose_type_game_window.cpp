#include "chose_type_game_window.h"
#include "ui_chose_type_game_window.h"

ChoseTypeGameWindow::ChoseTypeGameWindow(QWidget *parent)
    : QWidget(parent), ui(new Ui::ChoseTypeGameWindow) {
  ui->setupUi(this);
}

ChoseTypeGameWindow::~ChoseTypeGameWindow() { delete ui; }
