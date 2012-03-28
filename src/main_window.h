#ifndef MEIWEI_MAIN_WINDOW_H__
#define MEIWEI_MAIN_WINDOW_H__ 1

#include <QMainWindow>

class QLineEdit;
class QWebView;
class QUrl;

class MainWindow : public QMainWindow {
  Q_OBJECT;
public:
  MainWindow();
  MainWindow(const MainWindow&) = delete;
  MainWindow& operator=(const MainWindow&) = delete;

private slots:
  void loadPage();
  void changeUrl(const QUrl& url);

private:
  QWebView* web_view_;
  QLineEdit* url_edit_;
};

#endif  // MEIWEI_MAIN_WINDOW_H__
