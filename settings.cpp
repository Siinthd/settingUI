#include "settings.h"

settingutil::settingutil() : m_settings("settings.ini", QSettings::IniFormat) {
    SetDefaultSettings();
    ReadSettings();
}

void settingutil::ReadSettings() {
    m_settings.beginGroup("/Settings");
    m_hostname = m_settings.value("/Hostname", "").toString();
    m_username = m_settings.value("/Username", "").toString();
    m_portname = m_settings.value("/Portname", "").toString();
    m_settings.endGroup();
}

void settingutil::WriteSettings() {
    m_settings.beginGroup("/Settings");
    m_settings.setValue("/Hostname", m_hostname);
    m_settings.setValue("/Username", m_username);
    m_settings.setValue("/Portname", m_portname);
    m_settings.endGroup();
}

void settingutil::SetDefaultSettings() {
    m_hostname = "localhost";
    m_portname = "12345";
    m_username = "username";
}
std::string settingutil::getHostname() { return m_hostname.toStdString(); }
std::string settingutil::getUsername() { return m_username.toStdString(); }

std::string settingutil::getPortname() { return m_portname.toStdString(); }

void settingutil::setHostname(const QString& value) { m_hostname = value; }

void settingutil::setPortname(const QString& value) { m_portname = value; }

void settingutil::setUsername(const QString& value) { m_username = value; }
