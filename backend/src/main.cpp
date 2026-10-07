#include "../include/logger/Logger.h"
#include <iostream>
int main(){
	Logger* logger = Logger::getInstance();
	logger->config(true, true, true, true);

	logger->log("Initializing Logger");
	logger->debug("This is a debug message");
	logger->warning("This is a warning message");
	logger->error("This is an error message");
}
