#include "drawer.hpp"

namespace Managers {
    Drawer::Drawer(AssetResolver& assetResolver) {
        _assetResolver = &assetResolver;
    }

    void Drawer::update(sf::RenderWindow& window, std::unordered_map<std::string, GameCommon::Transform>& toUpdate) {
        for(auto& [key, value]: toUpdate) {
            auto texture = _assetResolver->getTexture(key);
            sf::Sprite sprite(texture);
            sprite.setPosition({value.x, value.y});
            sprite.setScale({value.scaleX, value.scaleY});
            sprite.setRotation(sf::Angle());
            window.draw(sprite);
        }
    }
}