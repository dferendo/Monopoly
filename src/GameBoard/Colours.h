//
// Created by dylan on 05/12/2016.
//

#ifndef MONOPOLY_COLOURS_H
#define MONOPOLY_COLOURS_H

#include <iostream>
using namespace std;

namespace GameBoard {
    enum Colour {
        Black, White, Purple, Light_Blue, Violet, Orange, Red, Yellow, Dark_Green, Dark_Blue
    };

    class Colours {
    public:
        static string getColourInString(Colour colour) {
            switch (colour) {
                case Black:
                    return "Black";
                case White:
                    return "White";
                case Purple:
                    return "Purple";
                case Light_Blue:
                    return "Light Blue";
                case Violet:
                    return "Violet";
                case Orange:
                    return "Orange";
                case Red:
                    return "Red";
                case Yellow:
                    return "Yellow";
                case Dark_Green:
                    return "Dark Green";
                case Dark_Blue:
                    return "Dark Blue";
                default:
                    return "Check Colour";
            }
        }
    };
}
#endif //MONOPOLY_COLOURS_H
