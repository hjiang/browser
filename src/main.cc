#include <QApplication>

#include "main_window.h"

int main(int argc, char** argv) {
  QApplication app(argc, argv);
  app.setOrganizationName("AVOS");
  app.setApplicationName("Browser");
  MainWindow main_win;
  main_win.show();
  return app.exec();
}
