//
// Created by gaeta on 05.05.2021.
//

#ifndef POO2_L4_BUFFY_COORDINATE_H
#define POO2_L4_BUFFY_COORDINATE_H

#include <cstddef>

class Coordinate {
    std::size_t x;
    std::size_t y;
public:
    Coordinate(std::size_t x, std::size_t y);

    bool operator==(const Coordinate &rhs) const;

    bool operator!=(const Coordinate &rhs) const;

    size_t getX() const;

    void setX(size_t x);

    size_t getY() const;

    void setY(size_t y);
};


#endif //POO2_L4_BUFFY_COORDINATE_H
