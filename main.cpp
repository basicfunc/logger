#include "logger.hpp"

int main() {
  Logger logger(INFO, "%I:%M %p ->");
  logger.setMessageFormat("{timestamp} {level}: {message}");
  logger.info("This is a info program");
  logger.warn("This is a warning program");
  logger.error("This is a error program");

  return 0;
}
