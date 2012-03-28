#include "browser_window.h"
#include "browser_window.moc"

#include <QPushButton>

#include "browser_tab.h"

BrowserWindow::BrowserWindow()
  : QTabWidget(nullptr) {
  setTabsClosable(true);
  setMovable(true);
  addBrowserTab(new BrowserTab(this));
  auto button = new QPushButton("+", this);
  setCornerWidget(button);
  connect(button, SIGNAL(clicked()), this, SLOT(addNewBrowserTab()));
}

void BrowserWindow::addBrowserTab(BrowserTab* tab) {
  addTab(tab, "New");
  connect(tab, SIGNAL(tabTitleChanged(BrowserTab*, const QString&)),
          this, SLOT(setTabTitle(BrowserTab*, const QString&)));
}

void BrowserWindow::addNewBrowserTab() {
  auto tab = new BrowserTab(this);
  addBrowserTab(tab);
  setCurrentWidget(tab);
}

void BrowserWindow::setTabTitle(BrowserTab* tab, const QString& title) {
  setTabText(indexOf(tab), title);
}
