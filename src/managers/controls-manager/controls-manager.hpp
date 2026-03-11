#ifndef CONTROLS_MANAGER_H
#define CONTROLS_MANAGER_H

#include <unordered_map>
#include <set>
#include <SFML/Graphics.hpp>

#include "../../enums/actions-enum.hpp"

namespace Managers {
    class ControlsManager {
        public:
            ControlsManager(const std::unordered_map<Actions, sf::Keyboard::Key>& keyMapping);
            const std::set<Actions>& getCurrentActions();
            void update();
        protected:
            std::unordered_map<Actions, sf::Keyboard::Key> _keysMapping;
            std::set<Actions> _currentActions;
    };
}

#endif