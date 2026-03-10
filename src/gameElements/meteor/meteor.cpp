#include "meteor.hpp"

namespace GameElements {
    Meteor::Meteor() {
        auto meteorPtr = std::make_unique<GameCommon::DrawableElement>();
        meteorPtr->img = "METEOR_1";
        meteorPtr->x = 100;
        meteorPtr->y = 100;
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