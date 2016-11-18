//
// Created by dylan on 17/11/2016.
//

#include "ReadInput.h"

int Util::readIntegerWithRange(int lowerRange, int upperRange) {
    string number;
    while(true) {
        try {
            getline(cin, number);
            // stoi will throw an exception if no numbers were given
            int givenLocation = stoi(number);
            if (givenLocation >= lowerRange && givenLocation <= upperRange) {
                return givenLocation;
            }
        } catch (invalid_argument error){};
        cout << "Invalid input, try again." << endl;
    }
}

string Util::readString() {
    string input;
    while (true) {
        getline(cin, input);
        if (!input.empty()) {
            return input;
        }
        cout << "Invalid input, try again." << endl;
    }
}
