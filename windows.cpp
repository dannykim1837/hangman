//
// Created by Danny kim on 5/19/24.
//

#include "windows.h"
#include <cstdlib>
#include <ctime>
#include <map>

void displayHangman(int tries) {
    switch (tries) {
        case 0:
            std::cout << "  +---+\n"
                      << "  |   |\n"
                      << "      |\n"
                      << "      |\n"
                      << "      |\n"
                      << "      |\n"
                      << "=========\n";
            break;
        case 1:
            std::cout << "  +---+\n"
                      << "  |   |\n"
                      << "  O   |\n"
                      << "      |\n"
                      << "      |\n"
                      << "      |\n"
                      << "=========\n";
            break;
        case 2:
            std::cout << "  +---+\n"
                      << "  |   |\n"
                      << "  O   |\n"
                      << "  |   |\n"
                      << "      |\n"
                      << "      |\n"
                      << "=========\n";
            break;
        case 3:
            std::cout << "  +---+\n"
                      << "  |   |\n"
                      << "  O   |\n"
                      << " /|   |\n"
                      << "      |\n"
                      << "      |\n"
                      << "=========\n";
            break;
        case 4:
            std::cout << "  +---+\n"
                      << "  |   |\n"
                      << "  O   |\n"
                      << " /|\\  |\n"
                      << "      |\n"
                      << "      |\n"
                      << "=========\n";
            break;
        case 5:
            std::cout << "  +---+\n"
                      << "  |   |\n"
                      << "  O   |\n"
                      << " /|\\  |\n"
                      << " /    |\n"
                      << "      |\n"
                      << "=========\n";
            break;
        case 6:
            std::cout << "  +---+\n"
                      << "  |   |\n"
                      << "  O   |\n"
                      << " /|\\  |\n"
                      << " / \\  |\n"
                      << "      |\n"
                      << "=========\n";
            break;
    }
}

