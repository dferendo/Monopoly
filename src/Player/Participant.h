//
// Created by dylan on 17/11/2016.
//

#ifndef MONOPOLY_PARTICIPANT_H
#define MONOPOLY_PARTICIPANT_H

#include <vector>
#include <iostream>
#include "Money.h"
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
    };
}
#endif //MONOPOLY_PARTICIPANT_H
