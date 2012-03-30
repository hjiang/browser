#include "config.h"

#include <QDir>

namespace meiwei {

Config::Config() {
  auto home_dir = QDir::homePath();
  config_path_ = home_dir + QDir::separator() + ".config" +
    QDir::separator() + "meiwei" + QDir::separator() + "browser";
  QDir::root().mkpath(config_path_);
}

}  // namespace meiwei
