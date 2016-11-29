//
// Created by dylan on 18/11/2016.
//

#include "Game.h"
#include "FillBoard.h"
#include "../Exception/NoHousesException.h"
#include "../Exception/HouseIsAlreadyMortgageException.h"
using namespace Exception;

GameMechanics::Game::Game() {
    // Initialise
    GameMechanics::fillGameBoard(gameBoard);
    GameMechanics::determinePlayers(participantsPlaying);
    GameMechanics::fillGroupColourSizeOfUpgradableProperties(groupColoursSize);
}

void GameMechanics::Game::play() {
    Dice dice;
    // Every player turn will have these options
    vector<string> displayMenu;

    displayMenu.push_back("Trade");
    displayMenu.push_back("Sell buildings(houses)");
    displayMenu.push_back("Player Profile");
    displayMenu.push_back("Mortgage");
    displayMenu.push_back("Move");

    // When only 1 participant left, he won
    while (participantsPlaying.size() != 1) {
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
                        Trade::tradePropertyBuyerKnown(this, participant);
                        break;
                    }
                    case 1: {
                        SellingBuilding::sellBuilding(participant);
                        break;
                    }
                    case 2: {
                        cout << participant->toString(*participant) << endl;
                        break;
                    }
                    case 3: {
                        mortgage(participant);
                        break;
                    }
                    // TODO remove it useless, handled by menu. So that IntelliJ doesnt complain
                    default:break;
                }
            }
            // Move will go to another player after execution
            Move::move(this, participant, &dice);
        }
        cout << "New turn!!" << endl;
        Util::pressEnterToContinue();
    }
}

void GameMechanics::Game::mortgage(Participant *participant) {
    vector<string> displayMenu;

    displayMenu.push_back("Mortgage a property");
    displayMenu.push_back("Remove mortgage (10% increase interest)");
    displayMenu.push_back("Return to previous menu");

    Util::displayMenu(displayMenu);
    int selection = Util::readIntegerWithRange(0, (int) displayMenu.size() - 1);
    if (selection == 0) {
        mortgageProperty(participant);
    } else if (selection == 1) {
        removeMortgageFromProperty(participant);
    }
    return;
}

void GameMechanics::Game::mortgageProperty(Participant *participant) {
    vector<GameBoard::Property *> nonImprovedProperties;
    try {
        participant->getNonImprovedParticipantProperties(nonImprovedProperties);
        Util::displayNonImprovedHouseForPlayer(participant, nonImprovedProperties);
        int mortgageBuildingIndex = Util::readIntegerWithRange(0, (int) nonImprovedProperties.size() - 1);
        GameBoard::Property * property = nonImprovedProperties[mortgageBuildingIndex];
        property->makePropertyMortgage(participant);
    } catch (NoHousesException &exception) {
        cout << exception.message << " Returning to previous menu." << endl;
    } catch (HouseIsAlreadyMortgageException &error) {
        // This exception can be remove by not letting the user see mortgaged building,
        // left to understand better concepts
        cout << error.message << " Returning to previous menu." << endl;
    }
}

void GameMechanics::Game::removeMortgageFromProperty(Participant *participant) {
    vector<GameBoard::Property *> mortgageProperties;
    try {
        participant->getMortgageParticipantProperties(mortgageProperties);
        Util::displayAllMortgageProperties(participant, mortgageProperties);
        int mortgageBuildingIndex = Util::readIntegerWithRange(0, (int) mortgageProperties.size() - 1);
        GameBoard::Property * property = mortgageProperties[mortgageBuildingIndex];
        property->removeMortgage(participant);
    } catch (NoHousesException &exception) {
        cout << exception.message << ". Returning to previous menu." << endl;
    }
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


