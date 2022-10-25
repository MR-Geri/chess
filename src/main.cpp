#include <src/gui/main_window/main_window.h>
#include <src/logic/figures/figures.h>

#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MainWindow w;
  w.show();
  return a.exec();
}
