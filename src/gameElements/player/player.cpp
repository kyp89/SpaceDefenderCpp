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
      _laserRightEmiterPoint.x = gunRightPtr->x - 7;
      _laserRightEmiterPoint.y = gunRightPtr->y;

      auto gunLeftPtr = std::make_unique<GameCommon::DrawableElement>();
      gunLeftPtr->img = "GUN";
      gunLeftPtr->index = 1;
      gunLeftPtr->x = 300.0f + 90;
      gunLeftPtr->y = 800.0f + 20;
      gunLeftPtr->scaleX = 1;
      gunLeftPtr->scaleY = 1;
      GUN_LEFT = gunLeftPtr.get();
      _laserLeftEmiterPoint.x = gunLeftPtr->x - 7;
      _laserLeftEmiterPoint.y = gunLeftPtr->y;

      _drawableElementsList.push_back(std::move(gunRightPtr));
      _drawableElementsList.push_back(std::move(gunLeftPtr));
      _drawableElementsList.push_back(std::move(shipPtr));
     }

   void Player::update(const std::set<Actions>& playerActions) {
      float SPEED = 20.0f;
      for(auto& action: playerActions) {
         if(action == Actions::PLAYER_MOBE_LEFT && (SHIP->x - SPEED < 0) == false) {
            SHIP->x -= SPEED;
            GUN_LEFT->x -= SPEED;
            GUN_RIGHT->x -= SPEED;
            _laserRightEmiterPoint.x -= SPEED;
            _laserLeftEmiterPoint.x -= SPEED;
         }
         if(action == Actions::PLAYER_MOVE_RIGHT &&  (SHIP->x + SPEED + 200 > 1000) == false) {
            SHIP->x += SPEED;
            GUN_LEFT->x += SPEED;
            GUN_RIGHT->x += SPEED;
            _laserRightEmiterPoint.x += SPEED;
            _laserLeftEmiterPoint.x += SPEED;
         }
         if(action == Actions::PLAYER_SHOOT) {
            //TODO: Emit laser
         }
      }
   }

   const std::vector<GameCommon::Point2D> Player::getLasersEmitterPoints() {
      std::vector<GameCommon::Point2D> laserEmitterPoints = {
         _laserLeftEmiterPoint,
         _laserRightEmiterPoint
      };
      return laserEmitterPoints;
   }


}