//
// Created by Danny kim on 5/19/24.
//

#ifndef CSE310_WINDOWS_H
#define CSE310_WINDOWS_H


#include <iostream>
#include <vector>
#include <string>

// 함수 선언
void displayHangman(int tries);
std::string getWord(const std::vector<std::string>& words, int wordLength);
void playGame(const std::vector<std::string>& words, int wordLength);
void showMainMenu();

#endif //CSE310_WINDOWS_H
