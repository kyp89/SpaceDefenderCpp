#ifndef LASER_H
#define LASER_H

#include <string>
#include <unordered_map>
#include <game-common/gameCommon.hpp>

namespace GameElements {
    class Laser: public GameCommon::DrawableContainer {
        public:
            Laser();
            void update();
            GameCommon::DrawableElement* LASER;
    };
}

#endif