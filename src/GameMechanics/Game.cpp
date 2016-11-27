//
// Created by dylan on 18/11/2016.
//

#include "Game.h"
#include "FillBoard.h"
#include "../Exception/NoHousesException.h"
#include "Trade.h"

GameMechanics::Game::Game() {
    // Initialise
    GameMechanics::fillGameBoard(gameBoard);
    GameMechanics::determinePlayers(participantsPlaying);
    GameMechanics::fillGroupColourSizeOfUpgradableProperties(groupColoursSize);
}

void GameMechanics::Game::play() {
    Dice dice;
    Trade trade;
    int turn = 0;
    vector<string> displayTradeOrSellMenu;

    displayTradeOrSellMenu.push_back("Trade");
    displayTradeOrSellMenu.push_back("Sell buildings(houses)");
    displayTradeOrSellMenu.push_back("Move");
    while (turn < 100) {
        int selection = 0;
        // Trade, sell property or move
        while (selection != 2) {
            Util::displayMenu(displayTradeOrSellMenu);
            selection = Util::readIntegerWithRange(0, 2);
            if (selection == 0) {
                trade.tradeProperty(this);
            } else if (selection == 1) {
                sellBuilding(getParticipantsPlaying());
            }
        }
        move(getParticipantsPlaying(), &dice);
        std::cout << "New turn!!" << std::endl;
        Util::pressEnterToContinue();
        turn++;
        // TODO tradeProperty
        // TODO sell properties at a offer (no houses on them)
        // TODO offer to sell houses, half price
    }
}

void GameMechanics::Game::move(vector<Player::Participant *> participantsPlaying, Dice *dice) {
    for(auto const& participant : participantsPlaying) {
        cout << "\033[1;31m" << participant->getName() << "'s turn." << "\033[0m" << endl;
        bool anotherTurnForPlayer = true;
        int counter = 0;
        while (anotherTurnForPlayer) {
            // Roll dice to move
            diceCount = generateDiceCount(dice);
            anotherTurnForPlayer = checkDiceDouble(dice);
            // If player did 2 turns and roll doubles again, move to the jail empty tail
            if (counter == 2 && anotherTurnForPlayer) {
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
}

void GameMechanics::Game::validateGoFunds(Player::Participant *participant, int location) {
    if (location >= TOTAL_TILES) {
        cout << "Adding Go Funds!!" << endl;
        participant->getMoney().addBalance(GO_AMOUNT);
        Util::pressEnterToContinue();
    }
}

bool GameMechanics::Game::checkDiceDouble(GameMechanics::Dice *dice) {
    pair<int, int> * diceRoll = dice->getCurrentDiceRoll();
    if (diceRoll->first == diceRoll->second) {
        cout << "Doubles!! Player gets another dice roll after doing a tile action unless it"
                "is the third consecutive time!" << endl;
        return true;
    }
    return false;
}

int GameMechanics::Game::generateDiceCount(GameMechanics::Dice *dice) {
    pair<int,int> * diceRoll = dice->generateNewDiceRoll();
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

void GameMechanics::Game::sellBuilding(vector<Player::Participant *> participantsPlaying) {

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
