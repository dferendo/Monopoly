//
// Created by dylan on 18/11/2016.
//

#include <map>
#include "../../include/GameMechanics/FillBoard.h"

using namespace GameBoard;
using namespace std;

void GameMechanics::FillBoard::fillGameBoard(vector<Tile *> &gameBoard) {
    // Purple houses (From 0 - 4)
    gameBoard.push_back(new Tile("Go"));
    gameBoard.push_back(createPurpleHouse("Mediterranean Avenue"));
    gameBoard.push_back(new Xorti("Xorti1"));
    gameBoard.push_back(createPurpleHouse("Baltic Avenue"));
    gameBoard.push_back(new Tax("Income Tax", 200));

    // RailRoad (5)
    gameBoard.push_back(createRailRoad("Reading Railroad"));

    // Light Blue houses (From 6 - 10)
    gameBoard.push_back(createLightBlueHouse("Oriental Avenue"));
    gameBoard.push_back(new Xorti("Xorti2"));
    gameBoard.push_back(createLightBlueHouse("Vermont Avenue"));
    gameBoard.push_back(createLightBlueHouse("Connecticut Avenue"));
    gameBoard.push_back(new Tile("Visiting Jail"));

    // Violet houses (From 10 - 14)
    gameBoard.push_back(createVioletHouse("St.Charles Place"));
    gameBoard.push_back(createUtilityHouse("Electric Company"));
    gameBoard.push_back(createVioletHouse("States Avenue"));
    gameBoard.push_back(createVioletHouse("Virginia Avenue"));

    // RailRoad (15)
    gameBoard.push_back(createRailRoad("Pennsylvania RailRoad"));

    // Orange houses (From 16 - 20)
    gameBoard.push_back(createOrangeHouse("St. James Place"));
    gameBoard.push_back(new Xorti("Xorti3"));
    gameBoard.push_back(createOrangeHouse("Tennessee Avenue"));
    gameBoard.push_back(createOrangeHouse("New York Avenue"));
    gameBoard.push_back(new Parking("Parking"));

    // Red houses (From 21 - 24)
    gameBoard.push_back(createRedHouse("Kentucky"));
    gameBoard.push_back(new Xorti("Xorti4"));
    gameBoard.push_back(createRedHouse("Indiana Avenue"));
    gameBoard.push_back(createRedHouse("Illinois Avenue"));

    // RailRoad (25)
    gameBoard.push_back(createRailRoad("B. & O. RailRoad"));

    // Yellow houses (From 26 - 30)
    gameBoard.push_back(createYellowHouse("Atlantic Avenue"));
    gameBoard.push_back(createYellowHouse("Ventnor Avenue"));
    gameBoard.push_back(createUtilityHouse("Water works"));
    gameBoard.push_back(createYellowHouse("Marvin Gardens"));
    gameBoard.push_back(new Tile("Go to jail"));

    // Dark Green houses (From 31 - 34)
    gameBoard.push_back(createDarkGreenHouse("Pacific Avenue"));
    gameBoard.push_back(createDarkGreenHouse("North Carolina Avenue"));
    gameBoard.push_back(new Xorti("Xorti5"));
    gameBoard.push_back(createDarkGreenHouse("Pennsylvania Avenue"));

    // RailRoad (35)
    gameBoard.push_back(createRailRoad("Short Line"));

    // Dark Blue houses (From 36 - 39)
    gameBoard.push_back(new Xorti("Xorti6"));
    gameBoard.push_back(createDarkBlueHouse("Park Place"));
    gameBoard.push_back(new Tax("Luxury Tax", 100));
    gameBoard.push_back(createDarkBlueHouse("Boardwalk"));
}

void GameMechanics::FillBoard::determinePlayers(vector<Player::Participant *> &participantsPlaying) {
    cout << "Enter the number of participants (2 to 8): ";
    int totalPlayers = Util::readIntegerWithRange(MINIMUM_PLAYERS, MAXIMUM_PLAYERS);
    for (int i = 0; i < totalPlayers; i++) {
        cout << "Participant " << i << ", enter your name: ";
        string participantName = Util::readString();
        participantsPlaying.push_back(new Player::Participant(i, participantName));
    }
}

UpgradableProperty* GameMechanics::FillBoard::createPurpleHouse(string houseName) {
    HousesPrice purpleHousePrice(50, 10, 30, 90, 160);
    return new UpgradableProperty(houseName, 60, 2, Purple, purpleHousePrice, 30);
}

GameBoard::RailRoad* GameMechanics::FillBoard::createRailRoad(string houseName) {
    return new RailRoad(houseName, 200, 25, Black, 100);
}

GameBoard::UpgradableProperty* GameMechanics::FillBoard::createLightBlueHouse(string houseName) {
    HousesPrice lightBlueHousePrice(50, 30, 90, 270, 400);
    return new UpgradableProperty(houseName, 100, 6, Light_Blue, lightBlueHousePrice, 50);
}

GameBoard::UpgradableProperty* GameMechanics::FillBoard::createVioletHouse(string houseName) {
    HousesPrice violetHousePrice(100, 50, 150, 450, 625);
    return new UpgradableProperty(houseName, 140, 10, Violet, violetHousePrice, 70);
}

GameBoard::UtilityProperty* GameMechanics::FillBoard::createUtilityHouse(string houseName) {
    return new UtilityProperty(houseName, 150, 4, White, 75);
}

GameBoard::UpgradableProperty* GameMechanics::FillBoard::createOrangeHouse(string houseName) {
    HousesPrice orangeHousePrice(100, 70, 200, 550, 750);
    return new UpgradableProperty(houseName, 180, 14, Orange, orangeHousePrice, 90);
}

GameBoard::UpgradableProperty* GameMechanics::FillBoard::createRedHouse(string houseName) {
    HousesPrice redHousePrice(150, 90, 250, 700, 875);
    return new UpgradableProperty(houseName, 220, 18, Red, redHousePrice, 110);
}

GameBoard::UpgradableProperty* GameMechanics::FillBoard::createYellowHouse(string houseName) {
    HousesPrice yellowHousePrice(150, 110, 330, 800, 975);
    return new UpgradableProperty(houseName, 260, 22, Yellow, yellowHousePrice, 130);
}

GameBoard::UpgradableProperty* GameMechanics::FillBoard::createDarkGreenHouse(string houseName) {
    HousesPrice darkGreenHousePrice(200, 130, 390, 900, 1100);
    return new UpgradableProperty(houseName, 300, 26, Dark_Green, darkGreenHousePrice, 150);
}

GameBoard::UpgradableProperty* GameMechanics::FillBoard::createDarkBlueHouse(string houseName) {
    HousesPrice darkBlueHousePrice(200, 200, 600, 1400, 1700);
    return new UpgradableProperty(houseName, 350, 35, Dark_Blue, darkBlueHousePrice, 175);
}

