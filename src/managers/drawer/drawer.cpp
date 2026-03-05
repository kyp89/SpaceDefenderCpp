#include "drawer.hpp"

namespace Managers {
    Drawer::Drawer(AssetResolver& assetResolver) {
        _assetResolver = &assetResolver;
    }

    void Drawer::addToUpdate(std::unordered_map<std::string, GameCommon::Transform>& toUpdate) {
        _toUpdate.push_back(toUpdate);
    }

    void Drawer::update(sf::RenderWindow& window) {
        for(auto& toUpdate: _toUpdate) {
            for(auto& [key, value]: toUpdate) {
                auto texture = _assetResolver->getTexture(key);
                sf::Sprite sprite(texture);
                sprite.setPosition({value.x, value.y});
                sprite.setScale({value.scaleX, value.scaleY});
                if(value.rotate > 0){
                    auto originX = sprite.getLocalBounds().size.x / 2;
                    auto originY = sprite.getLocalBounds().size.y / 2;
                    sprite.setOrigin({originX, originY});             
                    sprite.setRotation(sf::degrees(value.rotate));
                }
                window.draw(sprite);
            }
        }
        _toUpdate.clear();
    }
}