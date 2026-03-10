#include "laser.hpp"

namespace GameElements {
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
        if(LASER->y < 0) {
            LASER->y = 800;
        } else {
            LASER->y -= 10;
        }
    }
}