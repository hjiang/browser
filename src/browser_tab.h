#ifndef MEIWEI_BROWSER_TAB_H__
#define MEIWEI_BROWSER_TAB_H__ 1

#include <QMainWindow>

class QLineEdit;
class QWebView;
class QUrl;

class BrowserTab : public QMainWindow {
  Q_OBJECT;
public:
  explicit BrowserTab(QWidget* parent);
  BrowserTab(const BrowserTab&) = delete;
  BrowserTab& operator=(const BrowserTab&) = delete;

signals:
  void tabTitleChanged(BrowserTab* tab, const QString& title);

private slots:
  void loadPage();
  void changeUrl(const QUrl& url);
  void changeTitle(const QString& title);
  void loadFinished(bool success);

private:
  QWebView* web_view_;
  QLineEdit* url_edit_;
};

#endif  // MEIWEI_BROWSER_TAB_H__
