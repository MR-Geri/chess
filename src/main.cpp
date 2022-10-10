#include <src/game/game.h>

#include <QApplication>
#include <QTest>
#include <src/figure/figure.h>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Game w;
    w.show();
    return a.exec();
}
