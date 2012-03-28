#ifndef MEIWEI_BROWSER_WINDOW_H__
#define MEIWEI_BROWSER_WINDOW_H__ 1

#include <QTabWidget>

class BrowserTab;

class BrowserWindow: public QTabWidget {
  Q_OBJECT;
public:
  BrowserWindow();

private slots:
  //  void setTabTitle(BrowserTab* tab, const QString& title);

private:
  void addBrowserTab(BrowserTab* tab);
};

#endif  // MEIWEI_BROWSER_WINDOW_H__
