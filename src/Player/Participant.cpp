//
// Created by dylan on 17/11/2016.
//

#include <sstream>
#include "Participant.h"
#include "../Exception/NoPropertyException.h"
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

    bool Participant::isEqual(Participant *participant) {
        return participantId == participant->participantId;
    }

    int Participant::getSameGroupColourPropertiesAmount(string colourType) {
        int counter = 0;
        for (auto const &property : participantProperties) {
            if (property->getColour() == colourType) {
                counter++;
            }
        }
        return counter;
    }

    vector<GameBoard::Property *> Participant::getGroupColoursProperties(string colourType) {
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

    void Participant::getNonImprovedParticipantProperties(vector<GameBoard::Property *> &nonImprovedProperties) {
        for (auto &property : participantProperties) {
            if (property->getCurrentHousesBuild() == 0) {
                nonImprovedProperties.push_back(property);
            }
        }
        if (nonImprovedProperties.size() == 0) {
            throw NoPropertyException(*this);
        }
    }

    void Participant::getImprovedParticipantProperties(vector<GameBoard::Property *> &improvedProperties) {
        for (auto &property : participantProperties) {
            if (property->getCurrentHousesBuild() != 0) {
                improvedProperties.push_back(property);
            }
        }
        if (improvedProperties.size() == 0) {
            throw NoPropertyException(*this);
        }
    }

    void Participant::getMortgageParticipantProperties(vector<GameBoard::Property *> &mortgageProperties) {
        for (auto &property : participantProperties) {
            if (property->isPropertyMortgage()) {
                mortgageProperties.push_back(property);
            }
        }
        if (mortgageProperties.size() == 0) {
            throw NoPropertyException(*this);
        }
    }

//    ostream &Participant::operator<<(std::ostream &stream, const Participant &participant) {
//        stringstream properties;
//        properties << "Current properties: ";
//        if (participant.getParticipantProperties().size() == 0) {
//            properties << "Nothing";
//        } else {
//            for (auto &property : participant.getParticipantProperties()) {
//                // TODO fix comma
//                properties << property->getName() << ", ";
//            }
//        }
//        return stream << participant.getName() << " is at position: " << participant.getCurrentPosition() << "\n"
//                      << "Current balance: " << participant.getMoney().getBalance() << "\n"
//                      << properties.str();
//    }

    string Participant::toString(Participant &participant) {
        stringstream properties;
        stringstream message;
        properties << "Current properties: ";
        if (participant.getParticipantProperties().size() == 0) {
            properties << "Nothing";
        } else {
            for (auto &property : participant.getParticipantProperties()) {
                // TODO fix comma
                properties << property->getName() << ", ";
            }
        }
        message << participant.getName() << " is at position: " << participant.getCurrentPosition() << "\n"
                << "Current balance: " << participant.getMoney().getBalance() << "\n"
                << properties.str();
        return message.str();
    }
}
