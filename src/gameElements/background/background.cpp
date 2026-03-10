#include "background.hpp"

namespace GameElements {
    Background::Background() {
        auto bacgroundPtr = std::make_unique<GameCommon::DrawableElement>();
        bacgroundPtr->img = "BACKGROUND_BLUE";
        bacgroundPtr->x = 0;
        bacgroundPtr->y = 0;
        bacgroundPtr->scaleX = 4;
        bacgroundPtr->scaleY = 4;
        BACKGROUND_1 = bacgroundPtr.get();
        auto bacground2Ptr = std::make_unique<GameCommon::DrawableElement>();
        bacground2Ptr->img = "BACKGROUND_BLUE";
        bacground2Ptr->x = 0;
        bacground2Ptr->y = -1024;
        bacground2Ptr->scaleX = 4;
        bacground2Ptr->scaleY = 4;
        BACKGROUND_2 = bacground2Ptr.get();
        _drawableElementsList.push_back(std::move(bacground2Ptr));
        _drawableElementsList.push_back(std::move(bacgroundPtr));
    }

    void Background::update() {
        if(BACKGROUND_1->y >= 1024 + 8) {
            BACKGROUND_1->y = -1024;
        }else {
            BACKGROUND_1->y += 8;
        }
        if(BACKGROUND_2->y >= 1024 + 8) {
            BACKGROUND_2->y = -1024;
        }else {
            BACKGROUND_2->y += 8;
        }
    }
}