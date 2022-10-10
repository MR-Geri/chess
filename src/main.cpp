#include <src/game/game.h>
#include <src/figure/figure.h>

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Game w;
    w.show();
    return a.exec();
}
