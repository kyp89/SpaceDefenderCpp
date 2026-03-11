#include "player.hpp"

namespace GameElements {
    Player::Player() {
      auto shipPtr = std::make_unique<GameCommon::DrawableElement>();
      shipPtr->img = "PLAYER_SHIP";
      shipPtr->index = 2;
      shipPtr->x = 300.0f;
      shipPtr->y = 800.0f;
      shipPtr->scaleX = 1;
      shipPtr->scaleY = 1;
      SHIP = shipPtr.get();

      auto gunRightPtr = std::make_unique<GameCommon::DrawableElement>();
      gunRightPtr->img = "GUN";
      gunRightPtr->index = 1;
      gunRightPtr->x = 300.0f - 5;
      gunRightPtr->y = 800.0f + 20;
      gunRightPtr->scaleX = 1;
      gunRightPtr->scaleY = 1;
      GUN_RIGHT = gunRightPtr.get();

      auto gunLeftPtr = std::make_unique<GameCommon::DrawableElement>();
      gunLeftPtr->img = "GUN";
      gunLeftPtr->index = 1;
      gunLeftPtr->x = 300.0f + 90;
      gunLeftPtr->y = 800.0f + 20;
      gunLeftPtr->scaleX = 1;
      gunLeftPtr->scaleY = 1;
      GUN_LEFT = gunLeftPtr.get();

      _drawableElementsList.push_back(std::move(gunRightPtr));
      _drawableElementsList.push_back(std::move(gunLeftPtr));
      _drawableElementsList.push_back(std::move(shipPtr));
     }

     void Player::update(int move) {
      if(move == 1) {
         SHIP->x += 1;
         GUN_LEFT->x += 1;
         GUN_RIGHT->x += 1;
      } else {
         SHIP->x -= 1;
         GUN_LEFT->x -= 1;
         GUN_RIGHT->x -= 1;
      }
     }
}