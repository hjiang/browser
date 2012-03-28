#include "browser_window.h"
#include "browser_window.moc"

#include "browser_tab.h"

BrowserWindow::BrowserWindow()
  : QTabWidget(nullptr) {
  addBrowserTab(new BrowserTab(this));
}

void BrowserWindow::addBrowserTab(BrowserTab* tab) {
  addTab(tab, "New");
  connect(tab, SIGNAL(tabTitleChanged(BrowserTab*, const QString&)),
          this, SLOT(setTabTitle(BrowserTab*, const QString&)));
}

void BrowserWindow::setTabTitle(BrowserTab* tab, const QString& title) {
  setTabText(indexOf(tab), title);
}
