#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <set>

#include "enums/actions-enum.hpp"
#include "managers/assetResolver/assetResolver.hpp"
#include "managers/drawer/drawer.hpp"
#include <game-common/gameCommon.hpp>

#include "gameElements/player/player.hpp"
#include "gameElements/background/background.hpp"
#include "gameElements/projectiles/laser.hpp"
#include "managers/meteors-manager/meteors-manager.hpp"
#include "managers/controls-manager/controls-manager.hpp"
#include "managers/laser-manager/laser-manager.hpp"
#include "assetList.hpp"

const std::string APPLICATION_NAME = "SPACE DEFENDER";
const int GAME_FIELD_PX = 25;
const int GAME_FILED_H = 850;
const int GAME_FIELD_W = 1000;
const int GAME_FIELD_MARGIN = GAME_FIELD_PX;
const int FRAME_LIMIT = 60;
const std::string ASSETS_PATH = "assets";


const std::unordered_map<Actions, sf::Keyboard::Key> KEYS_MAPPING = {
    {
        Actions::PLAYER_MOBE_LEFT, sf::Keyboard::Key::A
    },
    {
        Actions::PLAYER_MOVE_RIGHT, sf::Keyboard::Key::D
    },
    {
        Actions::PLAYER_SHOOT, sf::Keyboard::Key::Space
    }
};