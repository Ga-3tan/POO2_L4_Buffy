//
// Created by gaeta on 05.05.2021.
//

#include <cmath>
#include "Field.h"
#include <limits>
#include <windows.h>

std::ostream& operator << (std::ostream& os, const Field& field) {
    COORD cursorPosition;
    cursorPosition.X = 0;
    cursorPosition.Y = 0;

    os << "+----------+" << std::endl;
    os << "|          |" << std::endl;
    os << "|          |" << std::endl;
    os << "|          |" << std::endl;
    os << "|          |" << std::endl;
    os << "|          |" << std::endl;
    os << "|          |" << std::endl;
    os << "+----------+" << std::endl;

    Sleep(1000);
    // update display
    cursorPosition.X = 5;
    cursorPosition.Y = 5;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
    os << 'c';
    //

    return field.display(os);
}

int Field::nextTurn() {
    // Déterminer les prochaines actions
    for (Humanoid* humanoid : humanoids) {
        humanoid->setAction(*this);
    }

    // Executer les actions
    for (Humanoid* humanoid : humanoids) {
        humanoid->executeAction(*this);
    }

    // Enlever les humanoides tués
    for (std::list<Humanoid*>::iterator it = humanoids.begin(); it != humanoids.end();) {
        if (!(*it)->isAlive()) {
            Humanoid* toDelete = *it;
            it = humanoids.erase(it); // suppression de l’élément dans la liste
            delete toDelete; // destruction de l’humanoide référencé
        } else {
            it++;
        }
    }
    return turn++;
}

Humanoid* Field::findNearby(Humanoid* from, const std::type_info& type) const {
    Humanoid *nearest = nullptr;
    std::size_t fromX = from->x();
    std::size_t fromY = from->y();
    double closestDistance = std::numeric_limits<double>::max();

    for (Humanoid* h : humanoids) {
        if (typeid(*h) == typeid(type)) {
            std::size_t otherX = h->x();
            std::size_t otherY = h->y();
            // calcul de la distance entre les 2 coordonées
            double tempClosestDistance = hypot(abs(otherX - fromX), abs(otherY - fromY));
            if (tempClosestDistance < closestDistance) {
                closestDistance = tempClosestDistance;
                nearest = h;
            }
        }
    }
    return nearest;
}

Field::Field(std::size_t size) : size(size), map(std::vector<std::vector<char>>(size,std::vector<char>(size,' '))) {

}

std::string getLine(size_t n) {
    return "+" + std::string(n, '-') + "+";
}

// TODO : possibilité de factoriser ça (les couleurs)
std::ostream& Field::display(std::ostream& os) const {
    COORD cursorPosition;

    for (auto h : humanoids) {
        cursorPosition.X = h->x();
        cursorPosition.Y = h->y();
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
        os << 'c';
    }

    return os;
//    os << getLine(size) << std::endl;
//    for (const std::vector<char>& line : map) {
//        os << "|";
//        for (char c : line) {
//            if (c == 'c') {
//                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2 /* get entity color */);
//                os << c;
//                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 /* get default color */);
//            } else {
//                os << c;
//            }
//        }
//        os << "|" << std::endl;
//    }
//    os << getLine(size) << std::endl;
//    return os;
}

void Field::updateDisplay(std::size_t x, std::size_t y, char c) {
    std::cout ;
}


