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
#include "../GameBoard/Go.h"
#include "../GameBoard/UpgradableProperty.h"
#include "../GameBoard/Xorti.h"
#include "../GameBoard/Tax.h"
#include "../GameBoard/EmptyTile.h"
#include "../GameBoard/UtilityProperty.h"
#include "../GameBoard/Parking.h"
#include "../Util/ReadInput.h"
#include "../GameMechanics/Dice.h"
#include "../GameBoard/RailRoad.h"

namespace GameMechanics {
    const int MINIMUM_PLAYERS = 2;
    const int MAXIMUM_PLAYERS = 8;

    void fillGameBoard(vector<GameBoard::Tile *> &gameBoard);
    void determinePlayers(vector<Player::Participant *> &participantsPlaying);
    void fillGroupColourSizeOfUpgradableProperties(map<string, int> &groupColoursSize);
}
#endif //MONOPOLY_FILLBOARD_H
