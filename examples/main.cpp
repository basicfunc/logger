#include "../include/logger.h"

int main(){
	Logger::setLogLevel(INFO);
	Logger::setMessageFormat("[{timestamp}] {level} - {message}");
	Logger::setTimestampFormat("%Y-%m-%d %I:%M:%S %p");
	Logger::setLogFile("log.txt");
	Logger::info("This is a info program");
	Logger::warn("This is a warning program");
	Logger::error("This is a error program");

	Logger::setLogLevel(ERR);
	Logger::info("Hi!");

	return 0;
}