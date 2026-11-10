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
			.abilityScores({
				{"strength", 0},
				{"dexterity", 0},
				{"constitution", 0},
				{"intelligence", 0},
				{"wisdom", 0},
				{"charisma", 0}
			})
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
	}catch(const exception& e){
		logger->error(e.what());
		return EXIT_FAILURE;
	}

	cout << player.serialize() << endl;

	return EXIT_SUCCESS;
}
