//
// Created by dylan on 05/12/2016.
//

#ifndef MONOPOLY_COLOURS_H
#define MONOPOLY_COLOURS_H

#include <iostream>
#include <map>

namespace GameBoard {
    enum ColourType {
        Black, White, Purple, Light_Blue, Violet, Orange, Red, Yellow, Dark_Green, Dark_Blue
    };

    class Colour {
    private:
        /**
         * File a map that for every colour has a value that shows how many properties there are
         * of same colours properties.
         */
        static std::map<GameBoard::ColourType, int> groupColourSize;
    public:
        /**
         * Get the enum type in string to print.
         * @param colour The colour of the property.
         * @return The colour of the property in string.
         */
        static std::string getColourInString(ColourType colour);

        /**
         * Get the amount of properties of the same colour for a specific enum of ColourType
         * @param colourType The enum of colourType
         * @return Returns the amount of properties of the same colour.
         */
        static int getGroupColoursSize(const GameBoard::ColourType colourType);
    };
}
#endif //MONOPOLY_COLOURS_H
