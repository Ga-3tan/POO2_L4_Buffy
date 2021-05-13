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
    cursorPosition.X = 5;
    cursorPosition.Y = 5;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

void Game::start(std::size_t gridSize) {
    Field field(gridSize);
    int currentTurn;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
//    ClearScreen();
    std::cout << field;


//    std::cout << field;
//    field.updateDisplay(3, 3, 'c');
//    Sleep(2000);
//    ClearScreen();
//    std::cout << "c";
    while(true);
//    while(currentTurn != 10) {
//        system("Color E4");
//        ClearScreen();
//        std::cout << field.display();
//        currentTurn = field.nextTurn();
//    }
}
