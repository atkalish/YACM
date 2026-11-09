#include "../include/logger/Logger.h"
#include "../include/player/Player.h"
#include "../include/Utils.h"

#include "../include/serdes/JsonSerializer.h"

int main(){
	Logger* logger = Logger::getInstance();
	logger->config(true, true, true, true);

	Player player;
	try{
		player = Player::Builder()
			.abilityScores(unordered_map<string, int>())
			.description(Player::Description::Builder()
							.name("Bob")
							.build())
			.personality(Player::Personality())
			.affiliations("no one")
			.backstory("Its very sad")
			.race(Race("githyanki.json"))
			.background(Background("faceless.json"))
			.playerClasses({PlayerClassBlueprint("wizard.json")})
			.build();
	}catch(const runtime_error& e){
		logger->error(e.what());
		return EXIT_FAILURE;
	}

	cout << player.serialize() << endl;

	return EXIT_SUCCESS;
}
