#include "controls-manager.hpp"

namespace Managers
{
    ControlsManager::ControlsManager(const std::unordered_map<Actions, sf::Keyboard::Key>& keysMapping):
    _keysMapping(keysMapping) {}

    void ControlsManager::update() {
        _currentActions.clear();
        for(const auto& [key, value]: _keysMapping) {
            if(sf::Keyboard::isKeyPressed(value)) {
                _currentActions.insert(key);
            }
        }
    }

    const std::set<Actions>& ControlsManager::getCurrentActions() {
        return _currentActions;
    }
}
