//
// Created by dylan on 17/11/2016.
//

#ifndef MONOPOLY_PARTICIPANT_H
#define MONOPOLY_PARTICIPANT_H

#include <vector>
#include <iostream>
#include "Money.h"
#include "../GameBoard/Property.h"

using namespace std;

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
        void moveCurrentPosition(int currentPosition);
        Money & getMoney();
        vector<GameBoard::Property *> getParticipantProperties();
        void addParticipantProperty(GameBoard::Property *property);
        bool isEqual(Participant *participant);
    };
}
#endif //MONOPOLY_PARTICIPANT_H
