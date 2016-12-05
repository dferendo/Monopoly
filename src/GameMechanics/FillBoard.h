//
// Created by dylan on 18/11/2016.
//

#ifndef MONOPOLY_FILLBOARD_H
#define MONOPOLY_FILLBOARD_H

#include <vector>
#include "../GameBoard/Tile.h"
#include "../Player/Participant.h"
#include "../Player/Participant.h"
#include "../GameBoard/Tile.h"
#include "../GameBoard/UpgradableProperty.h"
#include "../GameBoard/Xorti.h"
#include "../GameBoard/Tax.h"
#include "../GameBoard/UtilityProperty.h"
#include "../GameBoard/Parking.h"
#include "../Util/ReadInput.h"
#include "../GameMechanics/Dice.h"
#include "../GameBoard/RailRoad.h"
#include "../GameBoard/Colours.h"

namespace GameMechanics {
    const int MINIMUM_PLAYERS = 2;
    const int MAXIMUM_PLAYERS = 8;

    void fillGameBoard(vector<GameBoard::Tile *> &gameBoard);
    void determinePlayers(vector<Player::Participant *> &participantsPlaying);
    void fillGroupColourSizeOfUpgradableProperties(map<GameBoard::Colour, int> &groupColoursSize);

    // All houses will have same properties thus a method for all different type of houses Colours
    GameBoard::UpgradableProperty* createPurpleHouse(string houseName);
    GameBoard::RailRoad* createRailRoad(string houseName);
    GameBoard::UpgradableProperty* createLightBlueHouse(string houseName);
    GameBoard::UpgradableProperty* createVioletHouse(string houseName);
    GameBoard::UtilityProperty* createUtilityHouse(string houseName);
    GameBoard::UpgradableProperty* createOrangeHouse(string houseName);
    GameBoard::UpgradableProperty* createRedHouse(string houseName);
    GameBoard::UpgradableProperty* createYellowHouse(string houseName);
    GameBoard::UpgradableProperty* createDarkGreenHouse(string houseName);
    GameBoard::UpgradableProperty* createDarkBlueHouse(string houseName);
}
#endif //MONOPOLY_FILLBOARD_H
