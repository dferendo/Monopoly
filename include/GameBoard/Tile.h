//
// Created by dylan on 16/11/2016.
//

#ifndef MONOPOLY_TILE_H
#define MONOPOLY_TILE_H
#include <iostream>
#include "Colour.h"

namespace Player {
    class Participant;
}

namespace GameMechanics {
    class Game;
}

namespace GameBoard {
    class Tile {
    private:
        /**
         * The name of the property, will not changed throughout the game.
         */
        const std::string name;
    public:
        Tile(const std::string &name);

        /**
         * Returns the name of the property. It is declared virtual since it will be be overridden
         * by subclasses.
         * @return The name of the property
         */
        virtual std::string getName();

        /**
         * Action is called whenever a player lands on any Tile. This method is not abstract since
         * some methods can be empty.
         * @param participant The participant that landed on the Tile
         * @param game The whole board containing all the players and tiles.
         */
        virtual void action(Player::Participant * participant, GameMechanics::Game * game);

        virtual ~Tile();
    };
}

#endif //MONOPOLY_TILE_H
