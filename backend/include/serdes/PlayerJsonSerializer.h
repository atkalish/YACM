#pragma once

#include "../player/Player.h"
#include <nlohmann/json.hpp>

using namespace std;
using namespace nlohmann;

class PlayerJsonSerializer{
private:
    json j;

public:
    PlayerJsonSerializer(const Player& player);
    PlayerJsonSerializer() = delete;

    void exportPlayer(const string& filepath);
};