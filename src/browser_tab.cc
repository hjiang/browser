#include "browser_tab.h"

#include "browser_tab.moc"

#include <QDebug>
#include <QLineEdit>
#include <QToolBar>
#include <QNetworkRequest>
#include <QUrl>
#include <QWebView>

class RequestTracer: public QNetworkAccessManager {
public:
  QNetworkReply* createRequest(Operation op,
                               const QNetworkRequest& req,
                               QIODevice* outgoingData = nullptr) {
    qDebug() << req.url();
    return QNetworkAccessManager::createRequest(op, req, outgoingData);
  }
};


BrowserTab::BrowserTab(QWidget* parent)
  : QMainWindow(parent),
    web_view_(new QWebView(this)),
    url_edit_(new QLineEdit) {
  auto url_bar = new QToolBar;
  url_bar->addWidget(url_edit_);
  setCentralWidget(web_view_);
  addToolBar(Qt::TopToolBarArea, url_bar);
  web_view_->page()->setNetworkAccessManager(new RequestTracer);
  web_view_->load(QUrl("http://mei.fm"));
  connect(url_edit_, SIGNAL(returnPressed()), this, SLOT(loadPage()));
  connect(web_view_, SIGNAL(urlChanged(const QUrl&)),
          this, SLOT(changeUrl(const QUrl&)));
}

void BrowserTab::loadPage() {
  auto url = url_edit_->text();
  if (!url.startsWith("http://", Qt::CaseInsensitive) ||
      !url.startsWith("https://", Qt::CaseInsensitive)) {
    url = "http://" + url;
  }
  web_view_->load(QUrl(url));
}

void BrowserTab::changeUrl(const QUrl& url) {
  url_edit_->setText(url.toString());
}