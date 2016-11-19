//
// Created by dylan on 18/11/2016.
//

#include <map>
#include "FillBoard.h"
using namespace GameBoard;

void GameMechanics::fillGameBoard(vector<Tile *> &gameBoard) {
    // Xorti does not differ in the game, can use the same pointer
    Xorti * xorti = new Xorti("Xorti");
    gameBoard.push_back(new Go("Go"));
    gameBoard.push_back(new UpgradableProperty("Mediterranean Avenue", 60, 2, "PURPLE"));
    gameBoard.push_back(xorti);
    gameBoard.push_back(new UpgradableProperty("Baltic Avenue", 60, 2, "PURPLE"));
    gameBoard.push_back(new Tax("Income Tax", 200));
    gameBoard.push_back(new RailRoad("Reading Railroad", 200, 25, "BLACK"));
    gameBoard.push_back(new UpgradableProperty("Oriental Avenue", 100, 6, "LIGHT_BLUE"));
    gameBoard.push_back(xorti);
    gameBoard.push_back(new UpgradableProperty("Vermont Avenue", 100, 6, "LIGHT_BLUE"));
    gameBoard.push_back(new UpgradableProperty("Connecticut Avenue", 100, 6, "LIGHT_BLUE"));
    gameBoard.push_back(new EmptyTile("Visiting Jail"));
    gameBoard.push_back(new UpgradableProperty("St.Charles Place", 140, 10, "VIOLET"));
    gameBoard.push_back(new SpecialProperty("Electric Company", 150, 4, "WHITE"));
    gameBoard.push_back(new UpgradableProperty("States Avenue", 140, 10, "VIOLET"));
    gameBoard.push_back(new UpgradableProperty("Virginia Avenue", 140, 10, "VIOLET"));
    gameBoard.push_back(new RailRoad("Pennsylvania RailRoad", 200, 25, "BLACK"));
    gameBoard.push_back(new UpgradableProperty("St. James Place", 180, 14, "ORANGE"));
    gameBoard.push_back(xorti);
    gameBoard.push_back(new UpgradableProperty("Tennessee Avenue", 180, 14, "ORANGE"));
    gameBoard.push_back(new UpgradableProperty("New York Avenue", 180, 14, "ORANGE"));
    gameBoard.push_back(new Parking("Parking"));
    gameBoard.push_back(new UpgradableProperty("Kentucky", 220, 18, "RED"));
    gameBoard.push_back(xorti);
    gameBoard.push_back(new UpgradableProperty("Indiana Avenue", 220, 18, "RED"));
    gameBoard.push_back(new UpgradableProperty("Illinois Avenue", 220, 18, "RED"));
    gameBoard.push_back(new RailRoad("B. & O. RailRoad", 200, 25, "BLACK"));
    gameBoard.push_back(new UpgradableProperty("Atlantic Avenue", 260, 22, "YELLOW"));
    gameBoard.push_back(new UpgradableProperty("Ventnor Avenue", 260, 22, "YELLOW"));
    gameBoard.push_back(new SpecialProperty("Water works", 150, 4, "WHITE"));
    gameBoard.push_back(new UpgradableProperty("Marvin Gardens", 260, 22, "YELLOW"));
    gameBoard.push_back(new EmptyTile("Go to jail"));
    gameBoard.push_back(new UpgradableProperty("Pacific Avenue", 300, 26, "DARK_GREEN"));
    gameBoard.push_back(new UpgradableProperty("North Carolina Avenue", 300, 26, "DARK_GREEN"));
    gameBoard.push_back(xorti);
    gameBoard.push_back(new UpgradableProperty("Pennsylvania Avenue", 300, 26, "DARK_GREEN"));
    gameBoard.push_back(new RailRoad("Short Line", 200, 25, "BLACK"));
    gameBoard.push_back(xorti);
    gameBoard.push_back(new UpgradableProperty("Park Place", 350, 35, "DARK_BLUE"));
    gameBoard.push_back(new Tax("Luxury Tax", 100));
    gameBoard.push_back(new UpgradableProperty("Boardwalk", 400, 50, "DARK_BLUE"));
}

void GameMechanics::determinePlayers(vector<Player::Participant *> &participantsPlaying) {
    cout << "Enter the number of participants (2 to 8): ";
    int totalPlayers = Util::readIntegerWithRange(GameMechanics::MINIMUM_PLAYERS, GameMechanics::MAXIMUM_PLAYERS);
    for (int i = 0; i < totalPlayers; i++) {
        cout << "Participant " << i << ", enter your name: ";
        string participantName = Util::readString();
        participantsPlaying.push_back(new Player::Participant(i, participantName));
    }
}

void GameMechanics::fillGroupColourSizeOfUpgradableProperties(map<string, int> &groupColoursSize) {
    groupColoursSize.insert(pair<string, int> ("BLACK", 4));
    groupColoursSize.insert(pair<string, int> ("WHITE", 2));
    groupColoursSize.insert(pair<string, int> ("PURPLE", 2));
    groupColoursSize.insert(pair<string, int> ("LIGHT_BLUE", 3));
    groupColoursSize.insert(pair<string, int> ("VIOLET", 3));
    groupColoursSize.insert(pair<string, int> ("ORANGE", 3));
    groupColoursSize.insert(pair<string, int> ("RED", 3));
    groupColoursSize.insert(pair<string, int> ("YELLOW", 3));
    groupColoursSize.insert(pair<string, int> ("DARK_GREEN", 3));
    groupColoursSize.insert(pair<string, int> ("DARK_BLUE", 2));
}

