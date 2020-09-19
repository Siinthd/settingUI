#ifndef SETTINGUTIL_H
#define SETTINGUTIL_H
#include <QSettings>

// TODO: сделать ui для настройки

class settingutil {
public:
  settingutil();
  ~settingutil() { WriteSettings(); }
  void ReadSettings();
  void WriteSettings();
  void SetDefaultSettings();

  std::string getHostname();
  void setHostname();

  std::string getPortname();
  void setPortname();

  std::string getUsername();
  void setUsername();

private:
  QSettings m_settings;
  QString m_hostname;
  QString m_username;
  QString m_portname;
};

#endif // SETTINGUTIL_H
