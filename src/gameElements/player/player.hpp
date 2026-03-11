#ifndef _PLAYER_H
#define _PLAYER_H

#include <memory>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <game-common/gameCommon.hpp>

#include "../../enums/actions-enum.hpp"

namespace GameElements {
    class Player: public GameCommon::DrawableContainer {
        public:
            Player();
            void update(const std::set<Actions>& playerActions);
            const std::vector<GameCommon::Point2D> getLasersEmitterPoints();
            GameCommon::DrawableElement* SHIP;
            GameCommon::DrawableElement* GUN_LEFT;
            GameCommon::DrawableElement* GUN_RIGHT;
        protected:
            GameCommon::Point2D _laserLeftEmiterPoint;
            GameCommon::Point2D _laserRightEmiterPoint;
    };
}
#endif