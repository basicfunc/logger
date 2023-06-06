#include "logger.hpp"

int main() {
  Logger logger;
  logger.setLogFile("log.txt");
  logger.setMessageFormat("{timestamp} {level}: {message}");
  logger.info("This is a info program");
  logger.warn("This is a warning program");
  logger.error("This is a error program");

  logger << "Hi!";

  return 0;
}
