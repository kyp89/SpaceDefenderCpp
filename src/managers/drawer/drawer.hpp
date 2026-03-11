#ifndef DRAWER_H
#define DRAWER_H

#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <game-common/gameCommon.hpp>
#include "../assetResolver/assetResolver.hpp"

namespace Managers {
    class Drawer {
        public:
            Drawer(AssetResolver& assetResolver);
            void addToUpdate(const std::vector<std::unique_ptr<GameCommon::DrawableElement>>& toUpdate);
            void update(sf::RenderWindow& window);
        private:
            AssetResolver* _assetResolver;
            //TODO - upewnić się że wewnętrzne vectory to wskaźniki do vektorów od kontenerów
            std::vector<GameCommon::DrawableElement*> _toUpdate;
    };
}

#endif