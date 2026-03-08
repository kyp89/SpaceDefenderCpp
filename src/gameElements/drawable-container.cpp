#include "game-common/drawable-container/drawable-container.hpp"

namespace GameCommon {

    const std::vector<std::unique_ptr<GameCommon::DrawableElement>>& DrawableContainer::getDrawableElements() const
    {
        return _drawableElementsList;
    }

}