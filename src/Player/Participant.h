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
using namespace std;

namespace GameBoard {
    class Property;
}

namespace Player {

    class Participant {
    private:
        int participantId;
        int currentPosition;
        string name;
        Money money;
        // TODO make it map?
        vector<GameBoard::Property *> participantProperties;
    public:
        Participant(int participantId, const string &name);
        int getParticipantId() const;
        string getName();
        int getCurrentPosition();
        void setCurrentPosition(int currentPosition);
        Money & getMoney();
        vector<GameBoard::Property *> getParticipantProperties();
        void addParticipantProperty(GameBoard::Property *property);
        bool isEqual(Participant *participant);
        int getSameGroupColourProperties(string colourType);
    };
}
#endif //MONOPOLY_PARTICIPANT_H
