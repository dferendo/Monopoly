//
// Created by dylan on 18/11/2016.
//

#include "Game.h"
#include "FillBoard.h"
#include "../Exception/NoPropertyException.h"
#include "../Exception/PropertyIsAlreadyMortgageException.h"
using namespace Exception;

GameMechanics::Game::Game() {
    // Initialise
    GameMechanics::fillGameBoard(gameBoard);
    GameMechanics::determinePlayers(participantsPlaying);
    GameMechanics::fillGroupColourSizeOfUpgradableProperties(groupColoursSize);
}

void GameMechanics::Game::play() {
    Dice dice;
    unsigned long size;
    // Every player turn will have these options
    vector<string> displayMenu;

    displayMenu.push_back("Trade");
    displayMenu.push_back("Manage properties");
    displayMenu.push_back("Player Profile");
    displayMenu.push_back("Move");

    while (true) {
        // Not using foreach because when people are bankrupt they are removed from the list
        // and a player would repeat a turn.
        for (vector<Player::Participant>::size_type i = 0; i != participantsPlaying.size(); i++) {
            size = participantsPlaying.size();
            // Change terminal colour, better for reading
            cout << "\033[1;31m" << participantsPlaying[i]->getName() << "'s turn." << "\033[0m" << endl;
            int selection = 0;
            // Trade, sell property, display participant information or move
            while (selection != (int) displayMenu.size() - 1) {
                Util::displayMenu(displayMenu);
                selection = Util::readIntegerWithRange(0, (int) displayMenu.size() - 1);
                switch (selection) {
                    case 0: {
                        Trade::tradePropertyBuyerKnown(this, participantsPlaying[i]);
                        break;
                    }
                    case 1: {
                        manageProperties(participantsPlaying[i], this);
                        break;
                    }
                    case 2: {
                        cout << participantsPlaying[i]->toString(*participantsPlaying[i]) << endl;
                        break;
                    }
                    default:break;
                }
            }
            // Move will go to another player after execution
            Move::move(this, participantsPlaying[i], &dice);
            // If size is not equal to the participants size, there was a player that was bankrupt thus
            // the vector moved and the current player is located at the current index located by i.
            if (size != participantsPlaying.size()) {
                i--;
            }
        }
        // When only 1 participant left, he won
        if (participantsPlaying.size() == 1) {
            break;
        }
        cout << "New turn!!" << endl;
        Util::pressEnterToContinue();
    }
    cout << "Congratulation to " << participantsPlaying[0]->getName() << " for winning!" << endl;
}

void GameMechanics::Game::manageProperties(Participant *participant, GameMechanics::Game *game) {
    string input;
    try {
        std::vector<GameBoard::Property *> &properties = participant->getParticipantProperties();
        Util::displayHouseForPlayer(participant, properties);
        int sellBuildingPropertyIndex = Util::readIntegerWithRange(0, (int) properties.size() - 1);
        GameBoard::Property * property = properties[sellBuildingPropertyIndex];
        // If building has houses, it is an upgradeableProperty
        property->doActionWithoutBeingOnProperty(game);
    } catch (NoPropertyException &exception) {
        cout << exception.message << " Returning to previous menu." << endl;
    }
}

vector<Participant *> &GameMechanics::Game::getParticipantsPlaying() {
    return participantsPlaying;
}

int GameMechanics::Game::getGroupColoursSize(const GameBoard::Colour colourType) {
    map<GameBoard::Colour, int>::iterator it = groupColoursSize.find(colourType);
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

GameMechanics::Game::~Game() {
    // Clearing game board
    for (auto &tile : gameBoard) {
        delete tile;
    }
    // Clearing players
    for (auto &participant : participantsPlaying) {
        delete participant;
    }
}
