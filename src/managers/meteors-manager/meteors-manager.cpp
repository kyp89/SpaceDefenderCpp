#include "meteors-manager.hpp"

namespace Managers {
    MeteorsManager:: MeteorsManager(int posX, int posY, int boundX, int boundY):
    _posX(posX),
    _posY(posY),
    _boundX(boundX),
    _boundY(boundY) {};

    void MeteorsManager::emit() {
        int randomX = _posX + rand() % _boundX;
        int randomType = 1 + rand() % 4;
        auto meteor = std::make_unique<GameElements::Meteor>(randomX, _posY, randomType);
        _meteors.push_back(std::move(meteor));
    }

    void MeteorsManager::update(float deltaTime) {
        _spawnTimer += deltaTime;

        if (_spawnTimer >= _spawnInterval)
        {
            emit();
            _spawnTimer = 0.f;
        }
        for (auto it = _meteors.begin(); it != _meteors.end(); )
        {
            (*it)->update();

            if ((*it)->METEOR->y > _boundY) {
                it = _meteors.erase(it);
            }else {
                ++it;
            }
        }
    }

     const std::vector<std::unique_ptr<GameElements::Meteor>>& MeteorsManager::getMeteors() {
        return _meteors;
     };
}