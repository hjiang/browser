#include "browser_window.h"
#include "browser_window.moc"

#include "browser_tab.h"

BrowserWindow::BrowserWindow()
  : QTabWidget(nullptr) {
  addBrowserTab(new BrowserTab(this));
}

void BrowserWindow::addBrowserTab(BrowserTab* tab) {
  addTab(tab, "New");
}
