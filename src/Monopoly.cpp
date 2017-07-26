#include <fstream>
#include "../include/Monopoly.h"
#include "../include/GameMechanics/Game.h"
using namespace std;

void Monopoly::start() {
    vector<string> displayMenu = {"Play game", "User guide with assumptions made", "Quit"};
    int selection = 0;

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
    vector<string> displayMenu = {"Game objective", "Preparation", "The bank", "The play", "GO", "Buying property",
                                  "Paying rent", "Xorti", "Income tax", "Free parking", "Houses", "Selling property",
                                  "Mortgages", "Bankruptcy", "Go back"};
    int selection = 0;
    cout << "This menu includes the rules and assumptions made using the monopoly classic rules. "
            "\nIf there are no assumptions for a chapter, that means that all rules were followed." << endl;

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
    ifstream file("../doc/UserManual.txt");
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

