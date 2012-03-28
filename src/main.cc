#include <QApplication>
#include <QWebSettings>

#include "browser_window.h"

int main(int argc, char** argv) {
  QApplication app(argc, argv);
  app.setOrganizationName("AVOS");
  app.setApplicationName("Browser");
  BrowserWindow app_win;
  QWebSettings::globalSettings()
    ->setAttribute(QWebSettings::PluginsEnabled, true);
  app_win.show();
  return app.exec();
}
