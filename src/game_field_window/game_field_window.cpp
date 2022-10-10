#include "game_field_window.h"
#include "ui_game_field_window.h"

GameFieldWindow::GameFieldWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameFieldWindow) {
    ui->setupUi(this);

}

GameFieldWindow::~GameFieldWindow() {
    delete ui;
}
