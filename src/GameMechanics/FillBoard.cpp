//
// Created by dylan on 18/11/2016.
//

#include <map>
#include "FillBoard.h"
using namespace GameBoard;

void GameMechanics::fillGameBoard(vector<Tile *> &gameBoard) {
    // Xorti does not differ in the game, can use the same pointer
    Xorti * xorti = new Xorti("Xorti");
    HousesPrice purpleHousePrice(50, 10, 30, 90, 160);
    HousesPrice lightBlueHousePrice(50, 30, 90, 270, 400);
    HousesPrice violetHousePrice(100, 50, 150, 450, 625);
    HousesPrice orangeHousePrice(100, 70, 200, 550, 750);
    HousesPrice redHousePrice(150, 90, 250, 700, 875);
    HousesPrice yellowHousePrice(150, 110, 330, 800, 975);
    HousesPrice darkGreenHousePrice(200, 130, 390, 900, 1100);
    HousesPrice darkBlueHousePrice(200, 200, 600, 1400, 1700);

    gameBoard.push_back(new Tile("Go"));
    gameBoard.push_back(new UpgradableProperty("Mediterranean Avenue", 60, 2, "PURPLE", purpleHousePrice, 30));
    gameBoard.push_back(xorti);
    gameBoard.push_back(new UpgradableProperty("Baltic Avenue", 60, 2, "PURPLE", purpleHousePrice, 30));
    gameBoard.push_back(new Tax("Income Tax", 200));
    gameBoard.push_back(new RailRoad("Reading Railroad", 200, 25, "BLACK", 100));
    gameBoard.push_back(new UpgradableProperty("Oriental Avenue", 100, 6, "LIGHT_BLUE", lightBlueHousePrice, 50));
    gameBoard.push_back(xorti);
    gameBoard.push_back(new UpgradableProperty("Vermont Avenue", 100, 6, "LIGHT_BLUE", lightBlueHousePrice, 50));
    gameBoard.push_back(new UpgradableProperty("Connecticut Avenue", 100, 6, "LIGHT_BLUE", lightBlueHousePrice, 50));
    gameBoard.push_back(new Tile("Visiting Jail"));
    gameBoard.push_back(new UpgradableProperty("St.Charles Place", 140, 10, "VIOLET", violetHousePrice, 70));
    gameBoard.push_back(new UtilityProperty("Electric Company", 150, 4, "WHITE", 75));
    gameBoard.push_back(new UpgradableProperty("States Avenue", 140, 10, "VIOLET", violetHousePrice, 70));
    gameBoard.push_back(new UpgradableProperty("Virginia Avenue", 140, 10, "VIOLET", violetHousePrice, 70));
    gameBoard.push_back(new RailRoad("Pennsylvania RailRoad", 200, 25, "BLACK", 100));
    gameBoard.push_back(new UpgradableProperty("St. James Place", 180, 14, "ORANGE", orangeHousePrice, 90));
    gameBoard.push_back(xorti);
    gameBoard.push_back(new UpgradableProperty("Tennessee Avenue", 180, 14, "ORANGE", orangeHousePrice, 90));
    gameBoard.push_back(new UpgradableProperty("New York Avenue", 180, 14, "ORANGE", orangeHousePrice, 90));
    gameBoard.push_back(new Parking("Parking"));
    gameBoard.push_back(new UpgradableProperty("Kentucky", 220, 18, "RED", redHousePrice, 110));
    gameBoard.push_back(xorti);
    gameBoard.push_back(new UpgradableProperty("Indiana Avenue", 220, 18, "RED", redHousePrice, 110));
    gameBoard.push_back(new UpgradableProperty("Illinois Avenue", 220, 18, "RED", redHousePrice, 110));
    gameBoard.push_back(new RailRoad("B. & O. RailRoad", 200, 25, "BLACK", 100));
    gameBoard.push_back(new UpgradableProperty("Atlantic Avenue", 260, 22, "YELLOW", yellowHousePrice, 130));
    gameBoard.push_back(new UpgradableProperty("Ventnor Avenue", 260, 22, "YELLOW", yellowHousePrice, 130));
    gameBoard.push_back(new UtilityProperty("Water works", 150, 4, "WHITE", 75));
    gameBoard.push_back(new UpgradableProperty("Marvin Gardens", 260, 22, "YELLOW", yellowHousePrice, 130));
    gameBoard.push_back(new Tile("Go to jail"));
    gameBoard.push_back(new UpgradableProperty("Pacific Avenue", 300, 26, "DARK_GREEN", darkGreenHousePrice, 150));
    gameBoard.push_back(new UpgradableProperty("North Carolina Avenue", 300, 26, "DARK_GREEN", darkGreenHousePrice, 150));
    gameBoard.push_back(xorti);
    gameBoard.push_back(new UpgradableProperty("Pennsylvania Avenue", 300, 26, "DARK_GREEN", darkGreenHousePrice, 150));
    gameBoard.push_back(new RailRoad("Short Line", 200, 25, "BLACK", 100));
    gameBoard.push_back(xorti);
    gameBoard.push_back(new UpgradableProperty("Park Place", 350, 35, "DARK_BLUE", darkBlueHousePrice, 175));
    gameBoard.push_back(new Tax("Luxury Tax", 100));
    gameBoard.push_back(new UpgradableProperty("Boardwalk", 400, 50, "DARK_BLUE", darkBlueHousePrice, 175));
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

