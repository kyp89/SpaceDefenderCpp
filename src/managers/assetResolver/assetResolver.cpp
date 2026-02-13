#include "assetResolver.hpp"

namespace Managers {
    AssetResolver::AssetResolver(const std::string& assetPath, const std::unordered_map<std::string, std::string>& assetsMap):
    _assetManager(assetPath),
    _currentTextures() {
        for(auto [key, value]: assetsMap) {
            _assetManager.registerAsset(key, value);
        }
    }

    void AssetResolver::loadAsset(const std::string& assetKey) {
        auto texture = std::make_unique<sf::Texture>();
        auto path = _assetManager.resolvePath(assetKey);
        if(!path)
            throw std::runtime_error("Asset key not found");

        if(!texture->loadFromFile(*path))
            throw std::runtime_error("Failed to load texture");

        _currentTextures.insert({assetKey, std::move(texture)});
    }

    void AssetResolver::loadAssets(const std::set<std::string>& assetsKeys) {
        _currentTextures.clear();
        for(auto key: assetsKeys) {
            loadAsset(key);
        }
    }

    sf::Texture& AssetResolver::getTexture(const std::string& assetKey)  {
        return *_currentTextures.at(assetKey);
    }

}
