#ifndef DRAWER_H
#define DRAWER_H

#include <string>
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include <game-common/gameCommon.hpp>
#include "../assetResolver/assetResolver.hpp"

namespace Managers {
    class Drawer {
        public:
            Drawer(AssetResolver& assetResolver);
            void update(sf::RenderWindow& window, std::unordered_map<std::string, GameCommon::Transform>& toUpdate);
        private:
            AssetResolver* _assetResolver;
    };
}

#endif