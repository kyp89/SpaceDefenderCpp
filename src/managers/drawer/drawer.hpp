#ifndef DRAWER_H
#define DRAWER_H

#include <string>
#include <unordered_map>
#include <vector>
#include <SFML/Graphics.hpp>
#include <game-common/gameCommon.hpp>
#include "../assetResolver/assetResolver.hpp"

namespace Managers {
    class Drawer {
        public:
            Drawer(AssetResolver& assetResolver);
            void addToUpdate(std::unordered_map<std::string, GameCommon::Transform>& toUpdate);
            void update(sf::RenderWindow& window);
        private:
            AssetResolver* _assetResolver;
            std::vector<std::unordered_map<std::string, GameCommon::Transform>> _toUpdate;
    };
}

#endif