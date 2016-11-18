//
// Created by dylan on 16/11/2016.
//

#ifndef MONOPOLY_TILE_H
#define MONOPOLY_TILE_H
#include <iostream>
using namespace std;

// This forward declaration is needed since every tile action is done by a player, and every player has some tiles
// as property.
namespace Player {
    class Participant;
}

// This forward declaration is needed since some tiles require knowledge found at a current game.
namespace GameMechanics {
    class Game;
}

namespace GameBoard {
    const int TOTAL_TILES = 40;

    class Tile {
    private:
        string name;
    public:
        Tile(const string &name);
        const string &getName() const;
        virtual void action(Player::Participant * player, GameMechanics::Game * game) = 0;
    };
}

#endif //MONOPOLY_TILE_H
