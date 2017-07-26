//
// Created by dylan on 17/11/2016.
//

#ifndef MONOPOLY_PARTICIPANT_H
#define MONOPOLY_PARTICIPANT_H

#include <vector>
#include <iostream>
#include <map>
#include "Money.h"
#include "../GameBoard/Colour.h"
#include <algorithm>

namespace GameBoard {
    class Property;
}

namespace Player {

    class Participant {
    private:
        const double MONEY_TO_START = 1500;
        int participantId;
        int currentPosition = 0;
        std::string name;

        /**
         * Every participant start with a specific amount.
         */
        Money money = Money(name, MONEY_TO_START);

        /**
         * Properties can be bought by participants and are added here.
         */
        std::vector<GameBoard::Property *> participantProperties;
    public:
        Participant(int participantId, const std::string &name);

        std::string getName()const;

        int getCurrentPosition()const;

        void setCurrentPosition(int currentPosition);

        Money & getMoney();

        std::vector<GameBoard::Property *> & getParticipantProperties();

        /**
         * Add a property to the vector participantProperties.
         * @param property Property to be added.
         */
        void addParticipantProperty(GameBoard::Property *property);

        /**
         * Remove a property from the vector participantProperties.
         * @param property Property to be removed.
         */
        void removeProperty(GameBoard::Property *property);

        /**
         * Gets the amount of properties of the same ColourType from the properties owned by this participant.
         * @param colourType The ColourType to search the properties.
         * @return The amount of properties of the ColourType given.
         */
        int getSameGroupColourPropertiesAmount(GameBoard::ColourType colourType);

        /**
         * Returns a string with the information of the participant.
         * @return A string with the current position, name, properties and money of the participant.
         */
        std::string toString();

        /**
         * Compare this with another participant by their ID.
         * @param rhs The participant to compare this with.
         * @return True if participants are equal, false otherwise.
         */
        bool operator==(const Participant &rhs);
    };
}
#endif //MONOPOLY_PARTICIPANT_H
