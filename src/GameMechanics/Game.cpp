//
// Created by dylan on 18/11/2016.
//

#include "Game.h"
#include "FillBoard.h"
#include "../Exception/NoHousesException.h"

GameMechanics::Game::Game() {
    // Initialise
    GameMechanics::fillGameBoard(gameBoard);
    GameMechanics::determinePlayers(participantsPlaying);
    GameMechanics::fillGroupColourSizeOfUpgradableProperties(groupColoursSize);
}

void GameMechanics::Game::play() {
    Dice dice;
    Trade trade;
    Move move;
    int turn = 0;
    // Every player turn will have these options
    vector<string> displayMenu;

    displayMenu.push_back("Trade");
    displayMenu.push_back("Sell buildings(houses)");
    displayMenu.push_back("Player Profile");
    displayMenu.push_back("Mortgage");
    displayMenu.push_back("Move");

    // TODO proper ending
    while (turn < 100) {
        for (auto &participant : participantsPlaying) {
            // Change terminal colour, better for reading
            cout << "\033[1;31m" << participant->getName() << "'s turn." << "\033[0m" << endl;
            int selection = 0;
            // Trade, sell property, display participant information or move
            while (selection != 4) {
                Util::displayMenu(displayMenu);
                selection = Util::readIntegerWithRange(0, 4);
                switch (selection) {
                    case 0: {
                        trade.tradeProperty(this, participant);
                        break;
                    }
                    case 1: {
                        sellBuilding(participant);
                        break;
                    }
                    case 2: {
                        cout << participant->toString(*participant) << endl;
                        break;
                    }
                    case 3: {
                        mortgage();
                    }
                    // TODO remove it useless, handled by menu. So that IntelliJ doesnt complain
                    default:break;
                }
            }
            // Move will go to another player after execution
            move.move(this, participant, &dice);
        }
        cout << "New turn!!" << endl;
        Util::pressEnterToContinue();
        turn++;
    }
}

void GameMechanics::Game::sellBuilding(Participant *participant) {
    // TODO sell evenly
    string input;
    vector<GameBoard::Property *> nonImprovedProperties;
    try {
        participant->getImprovedParticipantProperties(nonImprovedProperties);
        Util::displayImprovedHouseForPlayer(participant, nonImprovedProperties);
        int sellBuildingPropertyIndex = Util::readIntegerWithRange(0, (int) nonImprovedProperties.size() - 1);
        GameBoard::Property * property = nonImprovedProperties[sellBuildingPropertyIndex];
        // If building has houses, it is an upgradeableProperty
        GameBoard::UpgradableProperty * upgradableProperty = dynamic_cast<GameBoard::UpgradableProperty *> (property);
        // Check if dynamic cast did not fail
        if (upgradableProperty) {
            cout << "Do you really want to remove a house? You will receive half the cost it took to build it. (Y/n)"
                 << endl;
            getline(cin, input);
            if (input[0] == 'Y' || input[0] == 'y') {
                upgradableProperty->setCurrentHousesBuild(upgradableProperty->getCurrentHousesBuild() - 1);
                participant->getMoney().addBalance(upgradableProperty->getHousesPrice().getPriceToUpgrade() / 2);
            }
        } else {
            // TODO check with JP for this thing
        }
    } catch (NoHousesException &exception) {
        cout << exception.message << ". Returning to previous menu." << endl;
    }
}

void GameMechanics::Game::mortgage() {

}

vector<Participant *> &GameMechanics::Game::getParticipantsPlaying() {
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

void GameMechanics::Game::setDiceCount(int diceCount) {
    Game::diceCount = diceCount;
}

