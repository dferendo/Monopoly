//
// Created by dylan on 18/11/2016.
//

#ifndef MONOPOLY_GAME_H
#define MONOPOLY_GAME_H

#include <vector>
#include "../GameBoard/Tile.h"

namespace GameMechanics {
    class Game {
    protected:
        vector<GameBoard::Tile *> gameBoard;
        vector<Player::Participant *> participantsPlaying;
    public:
        Game();
        void play();
    };
}
#endif //MONOPOLY_GAME_H
