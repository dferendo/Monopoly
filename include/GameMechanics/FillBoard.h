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
#include "Dice.h"
#include "../GameBoard/RailRoad.h"
#include "../GameBoard/Colour.h"

namespace GameMechanics {

    class FillBoard {
    private:
        const int MINIMUM_PLAYERS = 2;
        const int MAXIMUM_PLAYERS = 8;
    public:
        /**
         * Fill the gameBoard with the 40 properties.
         * @param gameBoard The vector that holds the Tiles.
         */
        void fillGameBoard(std::vector<GameBoard::Tile *> &gameBoard);

        /**
         * Determine the number of players with their names. Total participants is a number between 2 - 8.
         * The name of the participant cannot be empty.
         * @param participantsPlaying The vector that holds all the participants playing.
         */
        void determinePlayers(std::vector<Player::Participant *> &participantsPlaying);
    private:
        /**
         * All houses will have same properties thus a method for all different type of houses Colour.
         * @param houseName The name of the house
         * @return Returns a pointer that is allocated on the heap for the properties.
         */
        GameBoard::UpgradableProperty *createPurpleHouse(std::string houseName);

        GameBoard::RailRoad *createRailRoad(std::string houseName);

        GameBoard::UpgradableProperty *createLightBlueHouse(std::string houseName);

        GameBoard::UpgradableProperty *createVioletHouse(std::string houseName);

        GameBoard::UtilityProperty *createUtilityHouse(std::string houseName);

        GameBoard::UpgradableProperty *createOrangeHouse(std::string houseName);

        GameBoard::UpgradableProperty *createRedHouse(std::string houseName);

        GameBoard::UpgradableProperty *createYellowHouse(std::string houseName);

        GameBoard::UpgradableProperty *createDarkGreenHouse(std::string houseName);

        GameBoard::UpgradableProperty *createDarkBlueHouse(std::string houseName);
    };
}
#endif //MONOPOLY_FILLBOARD_H
