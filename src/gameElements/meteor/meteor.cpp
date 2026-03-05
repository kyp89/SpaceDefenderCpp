#include "meteor.hpp"

namespace GameElements {
    Meteor::Meteor():
    _textures{
        {
            "METEOR_1",
            GameCommon::Transform()
        }
    } {
        auto& transform = _textures["METEOR_1"];
        transform.x = 100;
        transform.y = 100;
        transform.scaleX = 1;
        transform.scaleY = 1;
    }

    void Meteor::update() {
        auto& transform = _textures["METEOR_1"];
        transform.y += 1 * METEOR_SPEED;
        transform.rotate += 1 * METEOR_SPEED;

    }

    const std::unordered_map<std::string, GameCommon::Transform>& Meteor::getTextureStatuses() const {
        return _textures;
    }
}