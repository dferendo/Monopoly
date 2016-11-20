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
            move(participant, dice);
        }
        std::cout << "New turn!!" << std::endl;
        Util::pressEnterToContinue();
        turn++;
    }
}

void GameMechanics::Game::validateGoFunds(Player::Participant *participant, int location) {
    if (location >= TOTAL_TILES) {
        cout << "Adding Go Funds!!" << endl;
        participant->getMoney().addBalance(GO_AMOUNT);
        Util::pressEnterToContinue();
    }
}

void GameMechanics::Game::move(Player::Participant *participant, Dice dice) {
    bool anotherTurnForPlayer = true;
    int counter = 0;
    while (anotherTurnForPlayer) {
        // Roll dice to move
        diceCount = generateDiceCount(dice);
        anotherTurnForPlayer = checkDiceDouble(dice);
        if (counter == 2) {
            cout << "Doubles for the third consecutive time!! Moving to jail." << endl;
            participant->setCurrentPosition(JAIL_TILE);
            Util::pressEnterToContinue();
            break;
        }
        determineParticipantLocation(participant, diceCount);
        gameBoard[participant->getCurrentPosition()]->action(participant, this);
        counter++;
        Util::pressEnterToContinue();
    }
}

bool GameMechanics::Game::checkDiceDouble(GameMechanics::Dice dice) {
    pair<int, int> * diceRoll = dice.getCurrentDiceRoll();
    return diceRoll->first == diceRoll->second;
}

int GameMechanics::Game::generateDiceCount(GameMechanics::Dice dice) {
    pair<int,int> * diceRoll = dice.generateNewDiceRoll();
    cout << "Dices rolled: " << diceRoll->first << ", " << diceRoll->second << endl;
    return diceRoll->first + diceRoll->second;
}

void GameMechanics::Game::determineParticipantLocation(Player::Participant *participant, int diceCount) {
    // Move player, if player reaches end of board go in the beginning of the board
    int newLocation = participant->getCurrentPosition() + diceCount;
    validateGoFunds(participant, newLocation);
    newLocation %= TOTAL_TILES;
    participant->setCurrentPosition(newLocation);
    cout << participant->getName() << " moved to position "
         << gameBoard[newLocation]->getName()
         << endl;
}

vector<Player::Participant *> &GameMechanics::Game::getParticipantsPlaying() {
    return participantsPlaying;
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


