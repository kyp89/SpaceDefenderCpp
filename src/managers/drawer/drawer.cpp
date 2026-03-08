#include "drawer.hpp"

namespace Managers {
    Drawer::Drawer(AssetResolver& assetResolver) {
        _assetResolver = &assetResolver;
    }

    void Drawer::addToUpdate(const std::vector<std::unique_ptr<GameCommon::DrawableElement>>& toUpdate) {
        for (const auto& e : toUpdate) {
            _toUpdate.push_back(e.get());
        }
    }

    void Drawer::update(sf::RenderWindow& window) {
        for(auto* e:_toUpdate) {
            auto texture = _assetResolver->getTexture(e->img);
            sf::Sprite sprite(texture);
                sprite.setPosition({e->x, e->y});
                sprite.setScale({e->scaleX, e->scaleY});
                if(e->rotate > 0){
                    auto originX = sprite.getLocalBounds().size.x / 2;
                    auto originY = sprite.getLocalBounds().size.y / 2;
                    sprite.setOrigin({originX, originY});             
                    sprite.setRotation(sf::degrees(e->rotate));
                }
                window.draw(sprite);
        }
        _toUpdate.clear();
    }
}