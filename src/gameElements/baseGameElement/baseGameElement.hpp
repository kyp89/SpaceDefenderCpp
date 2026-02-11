#ifndef BASEGAMEELEMENT_H
#define BASEGAMEELEMENT_H

#include <iostream>
#include <SFML/Graphics.hpp>

namespace GameElements
{
    class BaseGameElement {
        public:
            int width;
            int height;
            int x;
            int y;
            std::string key;
            void draw(sf::RenderTarget& target);
        protected:
            void clear();
    };
    
} // namespace GameElements

#endif
