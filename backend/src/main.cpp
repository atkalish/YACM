#include "../include/logger/Logger.h"
#include "../include/player/Player.h"
#include "../include/Utils.h"

#include "../include/serdes/JsonSerializer.h"

int main(){
	Logger* logger = Logger::getInstance();
	logger->config(true, true, true, true);

	Player player;
	try{
		player = Player::Builder().
			abilityScores(unordered_map<string, int>()).
			description(Player::Description()).
			personality(Player::Personality()).
			affiliations("").
			backstory("").
			race(Race("githyanki.json")).
			background(Background("faceless.json")).
			playerClasses({PlayerClassBlueprint("wizard.json")}).
			build();
	}catch(const runtime_error& e){
		logger->error(e.what());
		return EXIT_FAILURE;
	}

	logger->log(player.getBackground().getName());

	return EXIT_SUCCESS;
}
