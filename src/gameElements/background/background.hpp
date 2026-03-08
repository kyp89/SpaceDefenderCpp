#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <string>
#include <unordered_map>
#include <game-common/gameCommon.hpp>

namespace GameElements {
    class Background: public GameCommon::DrawableContainer {
        public:
            Background();
            void update();
            GameCommon::DrawableElement* BACKGROUND_1;
    };
}

#endif