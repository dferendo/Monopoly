//
// Created by dylan on 07/12/2016.
//
#include "../../include/GameBoard/Colour.h"
using namespace std;

namespace GameBoard {

    string Colour::getColourInString(ColourType colour) {
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

    int Colour::getGroupColoursSize(const GameBoard::ColourType colourType) {
        map<GameBoard::ColourType, int>::iterator it = groupColourSize.find(colourType);
        return it->second;
    }

    std::map<GameBoard::ColourType, int> Colour::groupColourSize = {
            std::pair<ColourType, int> (Black, 4),
            std::pair<ColourType, int> (White, 2),
            std::pair<ColourType, int> (Purple, 2),
            std::pair<ColourType, int> (Light_Blue, 3),
            std::pair<ColourType, int> (Violet, 3),
            std::pair<ColourType, int> (Orange, 3),
            std::pair<ColourType, int> (Red, 3),
            std::pair<ColourType, int> (Yellow, 3),
            std::pair<ColourType, int> (Dark_Green, 3),
            std::pair<ColourType, int> (Dark_Blue, 2)
    };

}