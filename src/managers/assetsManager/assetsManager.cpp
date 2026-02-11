#include "assetsManager.hpp"

std::map<std::string, std::string> TEXTURE_LIST = {
        {
            "PLAYER_SHIP",
            "playerShip.png"
        },
        {
            "BACKGROUND_BLUE",
            "backgroundBlue.png"
        }
    };

namespace Managers {
    AssetsManager::AssetsManager():
    _texturesFilesList(TEXTURE_LIST){
        init();
    }

    AssetsManager::~AssetsManager() {
        std::cerr << "AssetsManager destroyed: " << this << "\n";
    }

    void AssetsManager::init(){
        loadTextures();
    }

    sf::Texture& AssetsManager::getTexture(const std::string& key) {
        auto it = _textures.find(key);
        if (it == _textures.end())
            throw std::runtime_error("Texture not found: " + key);
        return it->second;
    }

    void AssetsManager::loadTextures(){
        for (const auto& [key, value] : _texturesFilesList){
            try{
                sf::Texture texture;
                std::string texturePath = ASSETS_IMAGES_PATH + value;
                std::cout << "Ładowanie: " << texturePath << "\n";
                if(texture.loadFromFile(texturePath)){
                    _textures.insert({key, texture});
                }
            }catch(const std::exception& e){
                std::cerr << "Błąd ładowania " << value << ": " << e.what() << "\n";
            }
        }
    }
}