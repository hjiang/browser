#include "browser_window.h"
#include "browser_window.moc"

#include <QPushButton>
#include <QTabBar>
#include <memory>

#include "browser_tab.h"

BrowserWindow::BrowserWindow()
  : QTabWidget(nullptr) {
  setTabsClosable(true);
  setMovable(true);
  addBrowserTab(new BrowserTab(this));
  auto button = new QPushButton("+", this);
  setCornerWidget(button);
  connect(button, SIGNAL(clicked()), this, SLOT(addNewBrowserTab()));
  connect(tabBar(), SIGNAL(tabCloseRequested(int)), this, SLOT(closeTab(int)));
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

void BrowserWindow::closeTab(int index) {
  std::unique_ptr<QWidget> tab_widget(widget(index));
  removeTab(index);
}
