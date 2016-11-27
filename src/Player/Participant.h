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
        string getName();
        int getCurrentPosition();
        void setCurrentPosition(int currentPosition);
        Money &getMoney();
        vector<GameBoard::Property *> &getParticipantProperties();
        void removeProperty(GameBoard::Property *property);
        vector<GameBoard::Property *> getGroupColoursProperties(string colourType);
        void addParticipantProperty(GameBoard::Property *property);
        bool isEqual(Participant *participant);
        int getSameGroupColourPropertiesAmount(string colourType);
        void getNonImprovedParticipantProperties(vector<GameBoard::Property *> &nonImprovedProperties);
        void getImprovedParticipantProperties(vector<GameBoard::Property *> &nonImprovedProperties);
    };
}
#endif //MONOPOLY_PARTICIPANT_H
