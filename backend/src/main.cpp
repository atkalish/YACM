#include "../include/logger/Logger.h"
#include "../include/player/Player.h"
#include "../include/Utils.h"

#include "../include/serdes/JsonSerializer.h"

int main(){
	Logger* logger = Logger::getInstance();
	logger->config(true, true, true, true);

	Player p1;
	try{
		p1 = Player::Builder()
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

	cout << p1.serialize().size() << endl;

	ofstream outfile(Player::SRC_DIR + "test1.json");
	outfile << p1.serialize();

	Player p2("test1.json");
	cout << p2.serialize().size() << endl;

	ofstream outfile2(Player::SRC_DIR + "test2.json");
	outfile2 << p2.serialize();

	return EXIT_SUCCESS;
}
