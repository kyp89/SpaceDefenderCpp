#ifndef METEOR_H
#define METERO_H

#include <string>
#include <unordered_map>
#include <game-common/gameCommon.hpp>

int const METEOR_SPEED = 2;

namespace GameElements
{
    class Meteor: public GameCommon::DrawableContainer {
        public:
            Meteor();
            void update();
            GameCommon::DrawableElement* METEOR;
    };
}

#endif