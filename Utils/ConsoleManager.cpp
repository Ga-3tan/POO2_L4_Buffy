/**
 * @file ConsoleManager.cpp
 * @authors Gaétan Zwick, Marco Maziero
 * @date 21.05.2021
 */

#include "ConsoleManager.h"
#include <windows.h>

void ConsoleManager::setCursorPosition(std::size_t x, std::size_t y) {
    COORD cursorPosition;
    cursorPosition.X = x;
    cursorPosition.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}
