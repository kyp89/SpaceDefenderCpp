#ifndef METEOR_H
#define METERO_H

#include <string>
#include <unordered_map>
#include <game-common/gameCommon.hpp>

int const METEOR_SPEED = 2;

namespace GameElements
{
    class Meteor
    {
        public:
            Meteor();
            void update();
            const std::unordered_map<std::string, GameCommon::Transform>& getTextureStatuses() const;
        protected:
            std::unordered_map<std::string, GameCommon::Transform> _textures;
    };
}


#endif