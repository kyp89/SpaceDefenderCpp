#include "background.hpp"

namespace GameElements {
    Background::Background() {
        auto bacgroundPtr = std::make_unique<GameCommon::DrawableElement>();
        bacgroundPtr->img = "BACKGROUND_BLUE";
        bacgroundPtr->x = 0;
        bacgroundPtr->y = 0;
        bacgroundPtr->scaleX = 5;
        bacgroundPtr->scaleY = 5;
        BACKGROUND_1 = bacgroundPtr.get();
        _drawableElementsList.push_back(std::move(bacgroundPtr));
    }

    void Background::update() {}

    // const std::vector<std::unique_ptr<GameCommon::DrawableElement>>& GameCommon::DrawableContainer::getDrawableElements() const {
    //     return _drawableElementsList;
    // }

}