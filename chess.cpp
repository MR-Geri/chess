#include "chess.h"
#include "./ui_chess.h"

Chess::Chess(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Chess)
{
    ui->setupUi(this);
}

Chess::~Chess()
{
    delete ui;
}

