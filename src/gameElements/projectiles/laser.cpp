#include "laser.hpp"

namespace GameElements {
    Laser::Laser(float x, float y) {
        auto laserPtr = std::make_unique<GameCommon::DrawableElement>();
        laserPtr->img = "LASER";
        laserPtr->x = x;
        laserPtr->y = y;
        laserPtr->scaleX = 1;
        laserPtr->scaleY = 1;
        LASER = laserPtr.get();
        _drawableElementsList.push_back(std::move(laserPtr));
    }
    Laser::Laser() {
        auto laserPtr = std::make_unique<GameCommon::DrawableElement>();
        laserPtr->img = "LASER";
        laserPtr->x = 300;
        laserPtr->y = 800;
        laserPtr->scaleX = 1;
        laserPtr->scaleY = 1;
        LASER = laserPtr.get();
        _drawableElementsList.push_back(std::move(laserPtr));
    }

    void Laser::update() {
        LASER->y -= 40;
    }
}