#ifndef ASSETSRESOLVER_H
#define ASSETSRESOLVER_H

#include <SFML/Graphics.hpp>
#include <Assets/AssetsManager.hpp>
#include <string>
#include <unordered_map>
#include <iostream>
#include <set>
#include <memory>


namespace Managers {
    class AssetResolver {
        public:
            AssetResolver(const std::string& assetPath, const std::unordered_map<std::string, std::string>& assetsMap);
            void loadAsset(const std::string& assetKey);
            void loadAssets(const std::set<std::string>& assetsKeys);
            sf::Texture& getTexture(const std::string& assetKey);
        protected:
            Assets::AssetsManager _assetManager;
            std::unordered_map<std::string, std::unique_ptr<sf::Texture>> _currentTextures;
    };
}

#endif