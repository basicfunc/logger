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

private:
  static LogLevel logLevel;
};

#endif // LOGGER_H
