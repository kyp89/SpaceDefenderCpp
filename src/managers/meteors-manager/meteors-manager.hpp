#ifndef METEORS_MANAGER_H
#define METEORS_MANAGER_H

#include <vector>
#include <memory>
#include <random>

#include "../../gameElements/meteor/meteor.hpp"

namespace Managers {
    class MeteorsManager {
        public:
            MeteorsManager(int posX, int posY, int boundX, int boundY);
            void update(float deltaTime);
            void emit();
            const std::vector<std::unique_ptr<GameElements::Meteor>>& getMeteors();
        protected:
            int _posX;
            int _posY;
            int _boundY;
            int _boundX;
            float _spawnTimer = 0.f;
            float _spawnInterval = 0.8f;
            std::vector<std::unique_ptr<GameElements::Meteor>> _meteors;
    };
}

#endif
