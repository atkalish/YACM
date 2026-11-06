#include "../include/logger/Logger.h"
#include "../include/player/Item.h"
#include "../include/Utils.h"

#include "../include/serdes/JsonSerializer.h"

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

	JsonSerializer js;
	js.addToList("names", "bob");
	js.addToList("names", "george");
	js.addToList("names", "fred");

	cout << js.str() << endl;

	return EXIT_SUCCESS;
}
