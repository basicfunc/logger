#include "../include/logger.h"

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif

LogLevel Logger::logLevel = INFO;

void Logger::setLogLevel(LogLevel level) {
  logLevel = level;
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

#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    WORD oldColorAttrs = csbi.wAttributes;

    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY);
    std::cout << colorCode << prefix << resetCode << message << std::endl;

    SetConsoleTextAttribute(hConsole, oldColorAttrs);
#else
    std::cout << colorCode << prefix << resetCode << message << std::endl;
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
