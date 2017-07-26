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
#include "Move.h"

namespace GameMechanics {
    const double GO_AMOUNT = 200;
    const int TOTAL_TILES = 40;
    const int JAIL_TILE = 10;

    class Game {
    private:
        /**
         * Holds all the Tiles of the game.
         */
        std::vector<GameBoard::Tile *> gameBoard;

        /**
         * Holds all the participants playing. Participants will be de-allocated if they go
         * Bankrupt.
         */
        std::vector<Player::Participant *> participantsPlaying;

        /**
         * The jackpot of the {@link GameBoard::Parking}. The amount is added every time a participants
         * pays a tax or a {@link GameBoard::xorti} fine.
         */
        double freeParkingJackpot = 0;

        int diceCount;
    public:
        /**
         * Initialise all the Tiles of the game and determine the participants playing.
         */
        Game();

        /**
         * Delete all instance alloacted to the heap. These are all the tiles and the participants playing.
         */
        virtual ~Game();

        /**
         * Can change properties of players.
         */
        std::vector<Player::Participant *> &getParticipantsPlaying();

        const std::vector<GameBoard::Tile *> &getGameBoard() const;

        int getDiceCount() const;

        void setDiceCount(int diceCount);

        double getFreeParkingJackpot() const;

        void setFreeParkingJackpot(double freeParkingJackpot);

        /**
         * The main method where players have their turn. The method will not stop until all participants
         * are bankrupt and their is only one participant left.
         */
        void play();

        /**
         * Get all the properties that the current participant has and choose one of his properties.
         * The {@link GameBoard::Property#doActionWithoutBeingOnProperty()} method is called to do
         * the actions a property can do without the participant being on the Property.
         * @param participant The participant that wants to manage his properties.
         * @param game The current game.
         */
        void manageProperties(Player::Participant* participant, GameMechanics::Game *game);
    };
}
#endif //MONOPOLY_GAME_H
