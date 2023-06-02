#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <string>

enum LogLevel {
  INFO,
  ERR,
  WARN
};

class Logger {
public:
  static void setLogLevel(LogLevel level);
  static void log(LogLevel level, const std::string& message);
  static void info(const std::string& message);
  static void error(const std::string& message);
  static void warn(const std::string& message);
  static void setTimestampFormat(const std::string& format);
  static void setMessageFormat(const std::string& format);
private:
  static LogLevel logLevel;
  static std::string timestampFormat;
  static std::string messageFormat;
};

#endif // LOGGER_H
