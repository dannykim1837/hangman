//
// Created by Danny kim on 5/19/24.
//

#include "windows.h"
#include <cstdlib>
#include <ctime>
#include <map>
#include <set>
#include <algorithm>


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

std::string getWord(const std::vector<std::string>& words, int wordLength) {
    std::vector<std::string> filteredWords;
    for (const auto& word : words) {
        if (word.length() == wordLength) {
            filteredWords.push_back(word);
        }
    }

    srand(time(0));
    int index = rand() % filteredWords.size();
    return filteredWords[index];
}

void displayAvailableLetters(const std::set<char>& guessedLetters) {
    std::cout << "Available letters: ";
    std::cout << "\n";
    for (char letter = 'a'; letter <= 'z'; ++letter) {
        if (guessedLetters.find(letter) == guessedLetters.end()) {
            std::cout << letter << " ";
        } else {
            std::cout << "_ ";
        }
    }
    std::cout << "\n";
}

void playGame(const std::vector<std::string>& words, int wordLength) {
    std::string word = getWord(words, wordLength);
    std::string guessedWord(word.length(), '_');
    int tries = 0;
    std::vector<char> incorrectGuesses;
    std::set<char> guessedLetters;
    bool won = false;

    while (tries < 6 && !won) {
        std::cout << "\nCurrent word: " << guessedWord << "\n";
        std::cout << "Incorrect guesses: ";
        for (char c : incorrectGuesses) std::cout << c << " ";
        std::cout << "\nTries left: " << 6 - tries << "\n";
        displayHangman(tries);

        displayAvailableLetters(guessedLetters);

        char guess;
        std::cout << "Enter a letter: ";
        std::cin >> guess;
        guess = tolower(guess);

        if (guessedLetters.find(guess) != guessedLetters.end()) {
            std::cout << "You've already guessed that letter.\n";
            continue;
        }

        guessedLetters.insert(guess);

        // Character 이미 추측되었는지 확인
        bool alreadyGuessed = false;
        for (char c : guessedWord) {
            if (c == guess) {
                alreadyGuessed = true;
                break;
            }
        }

        if (alreadyGuessed) {
            std::cout << "You've already guessed that letter.\n";
            continue;
        }

        bool correctGuess = false;
        for (int i = 0; i < word.length(); ++i) {
            if (word[i] == guess) {
                guessedWord[i] = guess;
                correctGuess = true;
            }
        }

        if (!correctGuess) {
            incorrectGuesses.push_back(guess);
            ++tries;
        }

        if (guessedWord == word) {
            won = true;
        }
    }

    if (won) {
        std::cout << "\nCongratulations! You've guessed the word: " << word << "\n";
    } else {
        std::cout << "\nSorry, you've been hanged. The word was: " << word << "\n";
    }
}

void showMainMenu() {
    std::cout << "\n=== Hangman Game ===\n";
    std::cout << "1. Start Game\n";
    std::cout << "2. Exit\n";
    std::cout << "Choose an option: ";
}
