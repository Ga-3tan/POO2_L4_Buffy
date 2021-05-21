#ifndef POO2_L4_BUFFY_CONSOLEMANAGER_H
#define POO2_L4_BUFFY_CONSOLEMANAGER_H

#include <cstddef>

/**
 * Class used to manage the visuals inside the program console
 *
 * @name ConsoleManager
 * @file ConsoleManager.h
 * @authors Gaétan Zwick, Marco Maziero
 * @date 21.05.2021
 */
class ConsoleManager {
public:
    /**
     * Sets the cursor at a certain position inside the console
     * @param x The x position
     * @param y The y position
     */
    static void setCursorPosition(std::size_t x, std::size_t y);
};

#endif //POO2_L4_BUFFY_CONSOLEMANAGER_H
