//
// Created by dylan on 18/11/2016.
//

#ifndef MONOPOLY_GAME_H
#define MONOPOLY_GAME_H

#include <vector>
#include <map>
#include "../GameBoard/Tile.h"
#include "Dice.h"
#include "../GameBoard/Property.h"

namespace GameMechanics {
    const double GO_AMOUNT = 200;
    const int TOTAL_TILES = 40;
    const int JAIL_TILE = 10;

    class Game {
    private:
        vector<GameBoard::Tile *> gameBoard;
        vector<Player::Participant *> participantsPlaying;
        map<string, int> groupColoursSize;
        double freeParkingJackpot = 0;
        int diceCount;
        void validateGoFunds(Player::Participant *participant, int location);
        void move(vector<Player::Participant *>, Dice *dice);
        void sellBuilding(vector<Player::Participant *> participantsPlaying);
        int generateDiceCount(Dice *dice);
        bool checkDiceDouble(Dice *dice);
        void determineParticipantLocation(Player::Participant *participant, int diceCount);
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

    };
}
#endif //MONOPOLY_GAME_H
