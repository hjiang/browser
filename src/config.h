#ifndef MEIWEI_INIT_H__
#define MEIWEI_INIT_H__ 1

#include <QString>

namespace meiwei {

class Config {
public:
  static const Config& instance() {
    static Config c;
    return c;
  }

  const QString& configPath() const { return config_path_; }

private:
  Config();
  QString config_path_;
};

}  // namespace meiwei

#endif  // MEIWEI_INIT_H__
