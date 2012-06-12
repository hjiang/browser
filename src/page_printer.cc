#include "page_printer.h"
// #include "page_printer.moc"

PagePrinter::PagePrinter(QWebView* view)
  : QObject(), view_(view) {
}

//PagePrinter::~PagePrinter() {}

void PagePrinter::loadFinished(bool success) {
  qDebug() << view_->page()->mainFrame()->toHtml();
  exit(0);
}
