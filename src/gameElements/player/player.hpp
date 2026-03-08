#ifndef _PLAYER_H
#define _PLAYER_H

#include <memory>
#include <string>
#include <vector>
#include <unordered_map>
#include <game-common/gameCommon.hpp>

namespace GameElements {
    class Player: public GameCommon::DrawableContainer {
        public:
            Player();
            void update(int move);
            GameCommon::DrawableElement* SHIP;
            GameCommon::DrawableElement* GUN_LEFT;
            GameCommon::DrawableElement* GUN_RIGHT;
    };
}
#endif