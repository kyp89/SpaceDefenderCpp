#include "background.hpp"

namespace GameElements {
    Background::Background():
    _textures{
        {
        "BACKGROUND_BLUE",
        GameCommon::Transform()
        }
     } {
        auto& transform = _textures["BACKGROUND_BLUE"];
        transform.x = 0;
        transform.y = 0;
        transform.scaleX = 5;
        transform.scaleY = 5;
    }

    void Background::update() {}

    const std::unordered_map<std::string, GameCommon::Transform>& Background::getTextureStatuses() const {
        return _textures;
    }
}