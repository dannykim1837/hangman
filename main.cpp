#include "windows.h"

int main() {
    std::vector<std::string> words = {
            "cat", "dog", "bat", "hat", "rat", "bee", "egg",
            "apple", "grape", "lemon", "peach", "cherry", "mango", "plum", "melon",
            "banana", "orange", "tomato", "carrot", "potato", "lettuce", "spinach",
            "strawberry", "blueberry", "blackberry", "raspberry", "pineapple", "cucumber"
    };

    while (true) {
        showMainMenu();

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            int wordLength;
            while (true) {
                std::cout << "Choose the length of the word (3 to 8): ";
                std::cin >> wordLength;
                if (wordLength >= 3 && wordLength <= 8) break;
                std::cout << "Invalid choice. Please choose a length between 3 and 8.\n";
            }

            playGame(words, wordLength);
        } else if (choice == 2) {
            std::cout << "Exiting the game. Goodbye!\n";
            break;
        } else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
