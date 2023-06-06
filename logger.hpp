#ifndef LOGGER_H
#define LOGGER_H

#include <chrono>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>

enum LogLevel { INFO, WARN, ERROR };

class Logger {
public:
  Logger(LogLevel level = INFO,
         const std::string &timestampFormat = "%Y-%m-%d %H:%M:%S",
         const std::string &messageFormat = "{timestamp} {level}: {message}")
      : logLevel(level), timestampFormat(timestampFormat),
        messageFormat(messageFormat) {}

  void setLogLevel(LogLevel level) { logLevel = level; }

  void setTimestampFormat(const std::string &format) {
    timestampFormat = format;
  }

  void setMessageFormat(const std::string &format) { messageFormat = format; }

  void setLogFile(const std::string &filename) {
    if (logFile.is_open())
      logFile.close(); // Close the existing log file, if any
    logFile.open(filename, std::ios::out | std::ios::app);
  }

  void log(LogLevel level, const std::string &message) {
    if (level >= logLevel) {
      std::string prefix;
      std::string colorPrefix;
      switch (level) {
      case INFO:
        prefix = "[INFO]";
        colorPrefix = "\033[1;34m[INFO]\033[0m";
        break;
      case ERROR:
        prefix = "[ERROR]";
        colorPrefix = "\033[1;31m[ERROR]\033[0m";
        break;
      case WARN:
        prefix = "[WARN]";
        colorPrefix = "\033[1;33m[WARN]\033[0m";
        break;
      }

      std::string logMessage = messageFormat;

      // Replace placeholders with actual values
      replacePlaceholder(logMessage, "{timestamp}", getFormattedTimestamp());
      replacePlaceholder(logMessage, "{level}", colorPrefix);
      replacePlaceholder(logMessage, "{message}", message);

      std::cout << logMessage << std::endl;

      std::ofstream logFile("log.txt",
                            std::ios::app); // Open log file in append mode
      if (logFile.is_open()) {
        logFile << logMessage << std::endl;
        logFile.close();
      }
    }
  }

  void info(const std::string &message) { log(INFO, message); }

  void error(const std::string &message) { log(ERROR, message); }

  void warn(const std::string &message) { log(WARN, message); }

private:
  LogLevel logLevel;
  std::string timestampFormat;
  std::string messageFormat;
  std::ofstream logFile;


  std::string getFormattedTimestamp() {
    if (!timestampFormat.empty()) {
      // Get current timestamp
      auto now = std::chrono::system_clock::now();
      std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

      // Format the timestamp
      char buffer[100];
      std::strftime(buffer, sizeof(buffer), timestampFormat.c_str(),
                    std::localtime(&currentTime));

      return buffer;
    }

    return "";
  }

  void replacePlaceholder(std::string &str, const std::string &placeholder,
                          const std::string &value) {
    size_t pos = str.find(placeholder);
    if (pos != std::string::npos) {
      str.replace(pos, placeholder.length(), value);
    }
  }

};

#endif // LOGGER_H
