#include <chrono>
#include <ctime>
#include "../include/logger.h"

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif

LogLevel Logger::logLevel = INFO;
std::string Logger::timestampFormat = "";

void Logger::setLogLevel(LogLevel level) {
  logLevel = level;
}

void Logger::setTimestampFormat(const std::string& format) {
  timestampFormat = format;
}

void Logger::log(LogLevel level, const std::string& message) {
  if (level >= logLevel) {
    std::string prefix;
    std::string colorCode;
    std::string resetCode;
    switch (level) {
      case INFO:
        prefix = "[INFO]:  ";
        colorCode = "\033[1m";
        resetCode = "\033[0m";
        break;
      case ERR:
        prefix = "[ERROR]: ";
        colorCode = "\033[1;33m";
        resetCode = "\033[0m";
        break;
      case WARN:
        prefix = "[WARN]:  ";
        colorCode = "\033[1;31m";
        resetCode = "\033[0m";
        break;
    }

    std::string time;

    // Append timestamp if a format is specified
    if (!timestampFormat.empty()) {
      // Get current timestamp
      auto now = std::chrono::system_clock::now();
      std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

      // Format the timestamp
      char buffer[100];
      std::strftime(buffer, sizeof(buffer), timestampFormat.c_str(), std::localtime(&currentTime));

      time = std::string(buffer) + ": ";
    }else{
      time = "";
    }

#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    WORD oldColorAttrs = csbi.wAttributes;

    std::cout << time;
    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY);
    std::cout << colorCode << prefix << resetCode << message << std::endl;

    SetConsoleTextAttribute(hConsole, oldColorAttrs);
#else
    std::cout << time << colorCode << prefix << resetCode << message << std::endl;
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
