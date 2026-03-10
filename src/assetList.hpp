#ifndef _ASSET_LIST_
#define _ASSET_LIST_

#include <unordered_map>
#include <string>

std::unordered_map<std::string, std::string> TEXTURE_LIST = {
        {
            "PLAYER_SHIP",
            "imgs/playerShip.png"
        },
        {
            "BACKGROUND_BLUE",
            "imgs/backgroundBlue.png"
        },
        {
            "METEOR_1",
            "imgs/meteor1.png"
        },
        {
            "GUN",
            "imgs/gun.png"
        },
        {
            "LASER",
            "imgs/laserGreen.png"
        }
    };

#endif