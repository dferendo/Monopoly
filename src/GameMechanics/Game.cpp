//
// Created by dylan on 18/11/2016.
//

#include "Game.h"
#include "FillBoard.h"

GameMechanics::Game::Game() {
    // Initialise
    GameMechanics::fillGameBoard(gameBoard);
    GameMechanics::determinePlayers(participantsPlaying);
}

void GameMechanics::Game::play() {
    Dice dice;
    int turn = 0;
    while (turn < 100) {
        for(auto const& participant : participantsPlaying) {
            cout << participant->getName() << " turns." << endl;
            // Roll dice to move
            std::pair<int, int> * diceRoll = dice.generateNewDiceRoll();
            int diceCount = diceRoll->first + diceRoll->second;
            cout << "Dices rolled " << diceCount << endl;
            // Move player, if player reaches end of board go in the beginning
            int newLocation = (participant->getCurrentPosition() + diceCount) % GameBoard::TOTAL_TILES;
            participant->setCurrentPosition(newLocation);
            cout << participant->getName() << " moved to position "
                 << gameBoard[newLocation]->getName()
                 << endl;
            gameBoard[newLocation]->action(participant, this);
        }
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