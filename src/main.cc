#include <QApplication>
#include <QWebSettings>
#include <QTabWidget>

#include "browser_tab.h"

int main(int argc, char** argv) {
  QApplication app(argc, argv);
  app.setOrganizationName("AVOS");
  app.setApplicationName("Browser");
  QTabWidget app_win;
  QWebSettings::globalSettings()
    ->setAttribute(QWebSettings::PluginsEnabled, true);
  app_win.addTab(new BrowserTab(&app_win), "blah");
  app_win.show();
  return app.exec();
}
