#include "../include/logger/Logger.h"
#include "../include/player/Player.h"
#include "../include/Utils.h"

#include "../include/serdes/JsonSerializer.h"

int main(){
	Logger* logger = Logger::getInstance();
	logger->config(true, true, true, true);

	Feature feature;
	try{
		feature = Feature("githyanki_feature.json");
	}catch(const runtime_error& e){
		logger->error(e.what());
		return EXIT_FAILURE;
	}

	cout << feature.serialize() << endl;

	return EXIT_SUCCESS;
}
