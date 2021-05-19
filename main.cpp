#include <iostream>
#include <stdexcept>
#include "Game.h"

int main(int argc, char** argv) {
    // TODO : Faire + de verifs
    if (argc < 4) throw std::invalid_argument("Arguments must be : <size> <nbHumans> <nbVampire>");
    Game game(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
    game.start();
    return 0;
}
