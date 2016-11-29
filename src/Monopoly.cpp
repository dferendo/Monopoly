#include <fstream>
#include "Monopoly.h"
#include "GameMechanics/Game.h"

void Monopoly::start() {
    vector<string> displayMenu;
    int selection = 0;

    displayMenu.push_back("Play game");
    displayMenu.push_back("User guide with assumptions made");
    displayMenu.push_back("Quit");

    cout << "Welcome to Mon\033[1;31mOOP\033[0moly!" << endl;
    while (selection != (int) displayMenu.size() - 1) {
        Util::displayMenu(displayMenu);
        selection = Util::readIntegerWithRange(0, (int) displayMenu.size() - 1);
        switch (selection) {
            case 0: {
                play();
                break;
            }
            case 1: {
                userManual();
                break;
            }
            default:break;
        }
    }
}

void Monopoly::play() {
    GameMechanics::Game game;
    game.play();
}

void Monopoly::userManual() {
    vector<string> displayMenu;
    int selection = 0;

    displayMenu.push_back("Game objective");
    displayMenu.push_back("Preparation");
    displayMenu.push_back("The bank");
    displayMenu.push_back("The play");
    displayMenu.push_back("GO");
    displayMenu.push_back("Buying property");
    displayMenu.push_back("Paying rent");
    displayMenu.push_back("Xorti");
    displayMenu.push_back("Income tax");
    displayMenu.push_back("Free parking");
    displayMenu.push_back("Houses");
    displayMenu.push_back("Selling property");
    displayMenu.push_back("Mortgages");
    displayMenu.push_back("Bankruptcy");
    displayMenu.push_back("Go back");

    while (true) {
        Util::displayMenu(displayMenu);
        selection = Util::readIntegerWithRange(0, (int) displayMenu.size() - 1);
        if (selection == (int) displayMenu.size() - 1) {
            break;
        }
        readFromFile(selection);
        Util::pressEnterToContinue();
    }
}

void Monopoly::readFromFile(int chapterNumber) {
    // Open file
    ifstream file("../resources/UserManual.txt");
    string readFromFile;
    int counter = 0;
    if (file) {
        while (getline(file, readFromFile)) {
            // Print the specific chapter
            if (counter == chapterNumber) {
                cout << readFromFile << endl;
            }
            // Each chapter is marked with an empty line
            if (readFromFile.empty()) {
                counter++;
            }
        }
    } else {
        cout << "Error opening file!" << endl;
    }
    // Close file
    file.close();
}

