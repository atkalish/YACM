#include "../include/logger/Logger.h"
#include "../include/player/Item.h"


int main(){
	Logger* logger = Logger::getInstance();
	logger->config(true, true, true, true);

	Item item;
	try{
		item = Item("costume.json");
	}catch(const runtime_error& e){
		logger->error(e.what());
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
