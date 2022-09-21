#include "chess.h"
#include "settings.h"
#include "menu.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Chess chess;
    Menu menu;
    Settings settings;
    menu.show();

    return a.exec();
}
