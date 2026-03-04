#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <string>
#include <unordered_map>
#include <game-common/gameCommon.hpp>

namespace GameElements {
    class Background {
        public:
            Background();
            void update();
            const std::unordered_map<std::string, GameCommon::Transform>& getTextureStatuses() const;
        protected:
            std::unordered_map<std::string, GameCommon::Transform> _textures;
    };
}

#endif