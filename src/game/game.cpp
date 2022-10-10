#include "game.h"
#include "ui_game.h"

Game::Game(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Game)
{
    ui->setupUi(this);

    ui->stackedWidget->addWidget(&menu_window);
    ui->stackedWidget->setCurrentIndex(1);
}

Game::~Game()
{
    delete ui;
}

