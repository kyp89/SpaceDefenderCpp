#ifndef _PLAYER_H
#define _PLAYER_H

#include <string>
#include <unordered_map>
#include <game-common/gameCommon.hpp>

namespace GameElements {
    class Player {
        public:
            Player();
            void update();
            const std::unordered_map<std::string, GameCommon::Transform>& getTextureStatuses() const;
        protected:
            std::unordered_map<std::string, GameCommon::Transform> _textures;
    };
}
#endif