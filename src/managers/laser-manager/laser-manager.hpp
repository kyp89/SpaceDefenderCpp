#ifndef LASER_MANAGER_H
#define LASER_MANAGER_H

#include <set>
#include <vector>
#include <memory>
#include <game-common/models/point2d.hpp>

#include "../../enums/actions-enum.hpp"
#include "../../gameElements/projectiles/laser.hpp"

namespace Managers {
    class LaserManager {
        public:
            LaserManager(int boundY);
            void update();
            void emit(const std::set<Actions>& playerActions, const std::vector<GameCommon::Point2D>& lasersEmitterPoints, float deltaTime);
            const std::vector<std::unique_ptr<GameElements::Laser>>& getLasers();
        protected:
            int _boundY;
            float _spawnTimer = 0.f;
            float _spawnInterval = 0.3f;
            std::vector<std::unique_ptr<GameElements::Laser>> _lasers;
    };
}
#endif