#ifndef POO2_L4_BUFFY_COORDINATE_H
#define POO2_L4_BUFFY_COORDINATE_H

#include <cstddef>

/**
 * Represents coordinates on a 2D axis
 *
 * @name Coordinate
 * @file Coordinate.h
 * @authors Gaétan Zwick, Marco Maziero
 * @date 21.05.2021
 */
class Coordinate {
    std::size_t x;
    std::size_t y;
public:
    /**
     * Constructor. Takes the x and y positions as parameters
     * @param x The x-axis position
     * @param y The y-axis position
     */
    Coordinate(std::size_t x, std::size_t y);

    /**
     * Retrieves the x-axis coordinate
     * @return The x-axis coordinate
     */
    std::size_t getX() const;

    /**
     * Sets the x-axis coordinate value
     * @param x The new value
     */
    void setX(size_t x);

    /**
     * Retrieves the y-axis coordinate
     * @return The y-axis coordinate
     */
    std::size_t getY() const;

    /**
     * Sets the y-axis coordinate value
     * @param y The new value
     */
    void setY(size_t y);
};


#endif //POO2_L4_BUFFY_COORDINATE_H
