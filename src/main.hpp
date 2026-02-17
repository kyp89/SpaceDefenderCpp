#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <set>

#include "managers/assetResolver/assetResolver.hpp"
#include <game-common/gameCommon.hpp>

#include "gameElements/player/player.hpp"
#include "assetList.hpp"

const std::string APPLICATION_NAME = "SPACE DEFENDER";
const int GAME_FIELD_PX = 25;
const int GAME_FILED_H = 900;
const int GAME_FIELD_W = 1000;
const int GAME_FIELD_MARGIN = GAME_FIELD_PX;
const int FRAME_LIMIT = 60;
const std::string ASSETS_PATH = "assets";