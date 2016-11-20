//
// Created by dylan on 18/11/2016.
//

#ifndef MONOPOLY_GAME_H
#define MONOPOLY_GAME_H

#include <vector>
#include <map>
#include "../GameBoard/Tile.h"

namespace GameMechanics {
    const double GO_AMOUNT = 200;
    const int TOTAL_TILES = 40;

    class Game {
    private:
        vector<GameBoard::Tile *> gameBoard;
        vector<Player::Participant *> participantsPlaying;
        map<string, int> groupColoursSize;
        double freeParkingJackpot = 0;
        int diceCount;
    public:
        Game();
        void play();
        // Can change properties of players
        vector<Player::Participant *> &getParticipantsPlaying();
        int getGroupColoursSize(string colourType);
        int getDiceCount() const;
        double getFreeParkingJackpot() const;
        void setFreeParkingJackpot(double freeParkingJackpot);
        const vector<GameBoard::Tile *> &getGameBoard() const;
        void addGoFunds(Player::Participant *participant);
    };
}
#endif //MONOPOLY_GAME_H
