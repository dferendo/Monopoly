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
#include "Trade.h"
using namespace Player;

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
        void validateGoFunds(Participant *participant, int location);
        Participant *determinePlayer(vector<Participant *> &participants);
        void move(vector<Participant *>, Dice *dice);
        void sellBuilding(vector<Participant *> &participantsPlaying);
        int generateDiceCount(Dice *dice);
        bool checkDiceDouble(Dice *dice);
        void determineParticipantLocation(Participant *participant, int diceCount);
        void displayParticipantProfile(vector<Participant *> &participants);
    public:
        Game();
        void play();
        // Can change properties of players
        vector<Participant *> &getParticipantsPlaying();
        int getGroupColoursSize(string colourType);
        int getDiceCount() const;
        double getFreeParkingJackpot() const;
        void setFreeParkingJackpot(double freeParkingJackpot);
        const vector<GameBoard::Tile *> &getGameBoard() const;

    };
}
#endif //MONOPOLY_GAME_H
