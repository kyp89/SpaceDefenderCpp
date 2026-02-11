#ifndef ASSETSMANAGER_H
#define ASSETSMANAGER_H

#include <SFML/Graphics.hpp>
#include <string>
#include <map>
#include <iostream>

const std::string ASSETS_IMAGES_PATH = "assets/imgs/";


namespace Managers {
    class AssetsManager {
        public:
            AssetsManager();
            sf::Texture& getTexture(const std::string& key);
            ~AssetsManager();
        protected:
            std::map<std::string, std::string> _texturesFilesList;
            std::map<std::string, sf::Texture> _textures;
            void init();
            void loadTextures();
    };
}

#endif