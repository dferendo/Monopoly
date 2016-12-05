//
// Created by dylan on 17/11/2016.
//

#ifndef MONOPOLY_PARTICIPANT_H
#define MONOPOLY_PARTICIPANT_H

#include <vector>
#include <iostream>
#include <map>
#include "Money.h"
#include "../GameBoard/Property.h"
#include <algorithm>

using namespace std;

namespace GameBoard {
    class Property;
}

namespace Player {

    class Participant {
    private:
        int participantId;
        int currentPosition = 0;
        string name;
        Money money = Money(1500);
        vector<GameBoard::Property *> participantProperties;
    public:
        Participant(int participantId, const string &name);
        string getName()const;
        int getCurrentPosition()const;
        void setCurrentPosition(int currentPosition);
        Money & getMoney();
        vector<GameBoard::Property *> & getParticipantProperties();
        void removeProperty(GameBoard::Property *property);
        vector<GameBoard::Property *> getGroupColoursProperties(string colourType);
        void addParticipantProperty(GameBoard::Property *property);
        // TODO operator ==
        bool isEqual(Participant *participant);
        int getSameGroupColourPropertiesAmount(string colourType);
        string toString(Participant& participant);
        // TODO ask JP for this << operator
//         ostream& operator<<(std::ostream& stream, const Participant& participant);
    };
}
#endif //MONOPOLY_PARTICIPANT_H
