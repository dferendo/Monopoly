//
// Created by dylan on 18/11/2016.
//

#include "FillBoard.h"

void GameMechanics::fillGameBoard(vector<GameBoard::Tile *> &gameBoard) {
    // Xorti does not differ in the game, can use the same pointer
    GameBoard::Xorti * xorti = new GameBoard::Xorti("Xorti");
    gameBoard.push_back(new GameBoard::Go("Go"));
    gameBoard.push_back(new GameBoard::UpgradableProperty("Mediterranean Avenue", 60, 2));
    gameBoard.push_back(xorti);
    gameBoard.push_back(new GameBoard::UpgradableProperty("Baltic Avenue", 60, 2));
    gameBoard.push_back(new GameBoard::Tax("Income Tax", 200));
    gameBoard.push_back(new GameBoard::Property("Reading Railroad", 200, 25));
    gameBoard.push_back(new GameBoard::UpgradableProperty("Oriental Avenue", 100, 6));
    gameBoard.push_back(xorti);
    gameBoard.push_back(new GameBoard::UpgradableProperty("Vermont Avenue", 100, 6));
    gameBoard.push_back(new GameBoard::UpgradableProperty("Connecticut Avenue", 100, 6));
    gameBoard.push_back(new GameBoard::EmptyTile("Visiting Jail"));
    gameBoard.push_back(new GameBoard::UpgradableProperty("ST.Charles Place", 140, 10));
    gameBoard.push_back(new GameBoard::SpecialProperty("Electric Company", 150, 4));
    gameBoard.push_back(new GameBoard::UpgradableProperty("States Avenue", 140, 10));
    gameBoard.push_back(new GameBoard::UpgradableProperty("Virginia Avenue", 140, 10));
    gameBoard.push_back(new GameBoard::Property("Pennsylvania RailRoad", 200, 25));
    gameBoard.push_back(new GameBoard::UpgradableProperty("St. James Place", 180, 14));
    gameBoard.push_back(xorti);
    gameBoard.push_back(new GameBoard::UpgradableProperty("Tennessee Avenue", 180, 14));
    gameBoard.push_back(new GameBoard::UpgradableProperty("New York Avenue", 180, 14));
    gameBoard.push_back(new GameBoard::Parking("Parking"));
    gameBoard.push_back(new GameBoard::UpgradableProperty("Kentucky", 220, 18));
    gameBoard.push_back(xorti);
    gameBoard.push_back(new GameBoard::UpgradableProperty("Indiana Avenue", 220, 18));
    gameBoard.push_back(new GameBoard::UpgradableProperty("Illinois Avenue", 220, 18));
    gameBoard.push_back(new GameBoard::Property("B. & O. RailRoad", 200, 25));
    gameBoard.push_back(new GameBoard::UpgradableProperty("Atlantic Avenue", 260, 22));
    gameBoard.push_back(new GameBoard::UpgradableProperty("Ventnor Avenue", 260, 22));
    gameBoard.push_back(new GameBoard::SpecialProperty("Water works", 150, 4));
    gameBoard.push_back(new GameBoard::UpgradableProperty("Marvin Gardens", 260, 22));
    gameBoard.push_back(new GameBoard::EmptyTile("Go to jail"));
    gameBoard.push_back(new GameBoard::UpgradableProperty("Pacific Avenue", 300, 26));
    gameBoard.push_back(new GameBoard::UpgradableProperty("North Carolina Avenue", 300, 26));
    gameBoard.push_back(xorti);
    gameBoard.push_back(new GameBoard::UpgradableProperty("Pennsylvania Avenue", 300, 26));
    gameBoard.push_back(new GameBoard::Property("Short Line", 200, 25));
    gameBoard.push_back(xorti);
    gameBoard.push_back(new GameBoard::UpgradableProperty("Park Place", 350, 35));
    gameBoard.push_back(new GameBoard::Tax("Luxury Tax", 100));
    gameBoard.push_back(new GameBoard::UpgradableProperty("Boardwalk", 400, 50));
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

