#include "../include/logger/Logger.h"
#include <iostream>
#include "serdes/JsonDeserializer.h"

int main(){
	Logger* logger = Logger::getInstance();
	logger->config(true, true, true, true);

	JsonDeserializer jsonDeserializer;
	try{
		jsonDeserializer = JsonDeserializer("tests/data/resources/items/pouch.json");
	}catch(const runtime_error& e){
		logger->error(e.what());
		return EXIT_FAILURE;
	}

	
	return EXIT_SUCCESS;
}
