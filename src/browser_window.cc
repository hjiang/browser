#include "browser_window.h"
#include "browser_window.moc"

#include <QPushButton>
#include <QTabBar>
#include <memory>

#include "browser_tab.h"

BrowserWindow::BrowserWindow()
  : QTabWidget(0) {
  setTabsClosable(true);
  setMovable(true);
  addBrowserTab(new BrowserTab(this));
  QPushButton* button = new QPushButton("+", this);
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
  BrowserTab* tab = new BrowserTab(this);
  addBrowserTab(tab);
  setCurrentWidget(tab);
}

void BrowserWindow::setTabTitle(BrowserTab* tab, const QString& title) {
  setTabText(indexOf(tab), title);
}

void BrowserWindow::closeTab(int index) {
  QWidget* tab_widget(widget(index));
  removeTab(index);
  delete tab_widget;
}
