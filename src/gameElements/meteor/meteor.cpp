#include "meteor.hpp"

namespace GameElements {
    Meteor::Meteor(float posX, float posY, int type) {
        auto meteorPtr = std::make_unique<GameCommon::DrawableElement>();
        meteorPtr->img = "METEOR_" + std::to_string(type);
        meteorPtr->x = posX;
        meteorPtr->y = posY;
        meteorPtr->scaleX = 1;
        meteorPtr->scaleY = 1;
        METEOR = meteorPtr.get();
        _drawableElementsList.push_back(std::move(meteorPtr));

    }

    void Meteor::update() {
        METEOR->y += 1 * METEOR_SPEED;
        METEOR->rotate += 1 * METEOR_SPEED;
        if(METEOR->y > 1024) {
            METEOR->y = -100;
        }
    }
}