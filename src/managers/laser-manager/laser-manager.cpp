#include "laser-manager.hpp"

namespace Managers {
    LaserManager::LaserManager(int boundY):
    _boundY(boundY){};

    void LaserManager::update() {
        for (auto it = _lasers.begin(); it != _lasers.end(); ){
            (*it)->update();
            if((*it)->LASER->y < _boundY) {
                it = _lasers.erase(it);
            }else {
                ++it;
            }
        }
    }

    void LaserManager::emit(const std::set<Actions>& playerActions, const std::vector<GameCommon::Point2D>& lasersEmitterPoints, float deltaTime) {
        _spawnTimer += deltaTime;

        if (_spawnTimer >= _spawnInterval)
        {
            _spawnTimer = 0.f;
        } else {
            return;
        }
        for(auto action: playerActions) {
            if(action == Actions::PLAYER_SHOOT) {
                for(auto& point: lasersEmitterPoints) {
                    auto laser = std::make_unique<GameElements::Laser>(point.x, point.y);
                    _lasers.push_back(std::move(laser));
                }
            }
        }
    }

    const std::vector<std::unique_ptr<GameElements::Laser>>& LaserManager::getLasers() {
        return _lasers;
    }
}