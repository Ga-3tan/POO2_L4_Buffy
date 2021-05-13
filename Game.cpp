//
// Created by gaeta on 05.05.2021.
//

#include "Game.h"
#include "GameLogic/Field.h"
#include <windows.h>
#include <iostream>
#include <unistd.h>

void ClearScreen() {
    // Function which cleans the screen without flickering
    COORD cursorPosition;
    cursorPosition.X = 0;
    cursorPosition.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

void Game::start(std::size_t gridSize) {
    Field field(gridSize);
    int currentTurn;

    system("Color 02");
    ClearScreen();
    std::cout << field.display();
    field.updateDisplay(3, 3, 'c');
    Sleep(5000);
    ClearScreen();
    std::cout << field.display();
    while(true);
//    while(currentTurn != 10) {
//        system("Color E4");
//        ClearScreen();
//        std::cout << field.display();
//        currentTurn = field.nextTurn();
//    }
}
