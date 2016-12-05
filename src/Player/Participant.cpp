//
// Created by dylan on 17/11/2016.
//

#include <sstream>
#include "Participant.h"
#include "../Exception/NoPropertyException.h"
#include "../GameBoard/Property.h"
using namespace Exception;

namespace Player {
    Participant::Participant(int participantId, const string &name) : participantId(participantId),
                                                                      name(name) {}

    string Participant::getName()const {
        return name;
    }

    Money & Participant::getMoney() {
        return money;
    }

    vector<GameBoard::Property *> & Participant::getParticipantProperties() {
        return participantProperties;
    }

    void Participant::addParticipantProperty(GameBoard::Property *property) {
        participantProperties.push_back(property);
    }

    int Participant::getCurrentPosition()const {
        return currentPosition;
    }

    void Participant::setCurrentPosition(int currentPosition) {
        Participant::currentPosition = currentPosition;
    }

    int Participant::getSameGroupColourPropertiesAmount(const GameBoard::Colour colourType) {
        int counter = 0;
        for (auto const &property : participantProperties) {
            if (property->getColour() == colourType) {
                counter++;
            }
        }
        return counter;
    }

    vector<GameBoard::Property *> Participant::getGroupColoursProperties(GameBoard::Colour colourType) {
        vector<GameBoard::Property *> groupColoursProperties;
        for (auto const &property : participantProperties) {
            if (property->getColour() == colourType) {
                groupColoursProperties.push_back(property);
            }
        }
        return groupColoursProperties;
    }

    void Participant::removeProperty(GameBoard::Property *property) {
        participantProperties.erase(remove(participantProperties.begin(), participantProperties.end(), property),
                                    participantProperties.end());
    }

    string Participant::toString(Participant &participant) {
        stringstream properties;
        string displayProperties;

        properties << "Current properties: ";
        if (participant.getParticipantProperties().size() == 0) {
            properties << "Nothing";
        } else {
            for (auto &property : participant.getParticipantProperties()) {
                properties << property->getName() << ", ";
            }
            displayProperties = properties.str().substr(0, properties.str().size() - 2);
        }
        stringstream message;
        message << participant.getName() << " is at position: " << participant.getCurrentPosition() << "\n"
                                                  << "Current balance: " << participant.getMoney().getBalance() << "\n"
                                                  << displayProperties;
        return message.str();
    }

    bool Participant::operator==(const Participant &rhs) {
        return this->participantId == rhs.participantId;
    }
}
