#pragma once

#include "../player/Player.h"
#include <nlohmann/json.hpp>

using namespace std;
using namespace nlohmann;

class PlayerJsonSerializer{
private:
    json data;

public:
    PlayerJsonSerializer(const Player& player);

    void exportPlayer(const string& filepath);
};