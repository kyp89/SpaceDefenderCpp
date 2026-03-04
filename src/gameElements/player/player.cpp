#include "player.hpp"

namespace GameElements {
    Player::Player():
    _textures{
        {
        "PLAYER_SHIP",
        GameCommon::Transform()
        }
     } {}

     void Player::update() {
        float x = 300.0f;
        float y = 300.0f;

        for(auto& [key, value]: _textures) {
            if(key == "PLAYER_SHIP") {
                value.x = x;
                value.y = y;
                value.scaleX = 1;
                value.scaleY = 1;
                value.rotate = 0;
            }
        }
     }

     const std::unordered_map<std::string, GameCommon::Transform>& Player::getTextureStatuses() const {
        return _textures;
     }
}