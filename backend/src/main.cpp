#include "../include/logger/Logger.h"
#include <iostream>
int main(){
	Logger* logger = Logger::getInstance();
	logger->config(false, true, false, false);

	logger->log("Initializing Logger");
	logger->debug("This is a debug message");
}
