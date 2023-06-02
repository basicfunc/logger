#include <chrono>
#include <ctime>
#include <iostream>
#include <string>
#include "../include/logger.h"

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif

LogLevel Logger::logLevel = INFO;
std::string Logger::timestampFormat = "";
std::string Logger::messageFormat = "{timestamp} {level} {message}";


void replacePlaceholder(std::string& str, const std::string& placeholder, const std::string& value) {
  size_t pos = str.find(placeholder);
  if (pos != std::string::npos) {
    str.replace(pos, placeholder.length(), value);
  }
}

std::string getFormattedTimestamp(std::string& timestampFormat) {
  if (!timestampFormat.empty()) {
    // Get current timestamp
    auto now = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

    // Format the timestamp
    char buffer[100];
    std::strftime(buffer, sizeof(buffer), timestampFormat.c_str(), std::localtime(&currentTime));

    return buffer;
  }

  return "";
}


void Logger::setLogLevel(LogLevel level) {
  logLevel = level;
}

void Logger::setTimestampFormat(const std::string& format) {
  timestampFormat = format;
}

void Logger::setMessageFormat(const std::string& format) {
  messageFormat = format;
}

void Logger::log(LogLevel level, const std::string& message) {
  if (level >= logLevel) {
    std::string prefix;
    switch (level) {
      case INFO:
        prefix = "\033[1m[INFO]:  \033[0m";
        break;
      case ERR:
        prefix = "\033[1;33m[ERROR]: \033[0m";
        break;
      case WARN:
        prefix = "\033[1;31m[WARN]:  \033[0m";
        break;
    }

    std::string logMessage = messageFormat;

    // Replace placeholders with actual values
    replacePlaceholder(logMessage, "{timestamp}", getFormattedTimestamp(Logger::timestampFormat));
    replacePlaceholder(logMessage, "{level}", prefix);
    replacePlaceholder(logMessage, "{message}", message);

#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    WORD oldColorAttrs = csbi.wAttributes;

    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY);
    std::cout << "\033[0m" << logMessage << std::endl;

    SetConsoleTextAttribute(hConsole, oldColorAttrs);
#else
    std::cout << "\033[0m" << logMessage << std::endl;
#endif
  }
}

void Logger::info(const std::string& message) {
  log(INFO, message);
}

void Logger::error(const std::string& message) {
  log(ERR, message);
}

void Logger::warn(const std::string& message) {
  log(WARN, message);
}