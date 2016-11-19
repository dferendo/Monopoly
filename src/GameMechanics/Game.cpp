//
// Created by dylan on 18/11/2016.
//

#include "Game.h"
#include "FillBoard.h"

GameMechanics::Game::Game() {
    // Initialise
    GameMechanics::fillGameBoard(gameBoard);
    GameMechanics::determinePlayers(participantsPlaying);
    GameMechanics::fillGroupColourSizeOfUpgradableProperties(groupColoursSize);
}

void GameMechanics::Game::play() {
    Dice dice;
    int turn = 0;
    while (turn < 100) {
        for(auto const& participant : participantsPlaying) {
            cout << participant->getName() << " turns." << endl;
            // Roll dice to move
            pair<int,int> * diceRoll = dice.generateNewDiceRoll();
            diceCount = diceRoll->first + diceRoll->second;
            cout << "Dices rolled " << diceCount << endl;
            // Move player, if player reaches end of board go in the beginning
            int newLocation = (participant->getCurrentPosition() + diceCount) % GameBoard::TOTAL_TILES;
            participant->setCurrentPosition(newLocation);
            cout << participant->getName() << " moved to position "
                 << gameBoard[newLocation]->getName()
                 << endl;
            gameBoard[newLocation]->action(participant, this);
            Util::pressEnterToContinue();
        }
        std::cout << "New turn!!" << std::endl;
        Util::pressEnterToContinue();
        turn++;
    }
}

vector<Player::Participant *> &GameMechanics::Game::getParticipantsPlaying() {
    return participantsPlaying;
}

Player::Participant * GameMechanics::Game::getParticipant(vector<Player::Participant *> participantsPlaying,
                                                          int participantId) {
    for (auto const &participant : participantsPlaying) {
        if (participant->getParticipantId() == participantId) {
            return participant;
        }
    }
}

int GameMechanics::Game::getGroupColoursSize(string colourType) {
    map<string, int>::iterator it = groupColoursSize.find(colourType);
    return it->second;
}

int GameMechanics::Game::getDiceCount() const {
    return diceCount;
}

double GameMechanics::Game::getFreeParkingJackpot() const {
    return freeParkingJackpot;
}

void GameMechanics::Game::setFreeParkingJackpot(double freeParkingJackpot) {
    Game::freeParkingJackpot = freeParkingJackpot;
}

const vector<GameBoard::Tile *> &GameMechanics::Game::getGameBoard() const {
    return gameBoard;
}
