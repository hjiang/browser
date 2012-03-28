#include <QApplication>
#include <QWebSettings>

#include "main_window.h"

int main(int argc, char** argv) {
  QApplication app(argc, argv);
  app.setOrganizationName("AVOS");
  app.setApplicationName("Browser");
  QWebSettings::globalSettings()
    ->setAttribute(QWebSettings::PluginsEnabled, true);
  MainWindow main_win;
  main_win.show();
  return app.exec();
}
