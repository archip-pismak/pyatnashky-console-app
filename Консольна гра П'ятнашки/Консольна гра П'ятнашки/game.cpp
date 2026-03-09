#include "game.h"
#include <iostream>
#include <iomanip>

void GameField::init(int d) {
    size = d;
    status = ACTIVE;

    // Виділення пам'яті
    board = new int* [size];
    for (int i = 0; i < size; i++) {
        board[i] = new int[size];
    }

    int value = size * size - 1; // Починаємо з максимального значення

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == size - 1 && j == size - 1) {
                board[i][j] = 0; // Пуста клітинка в кінці
                emptyRow = i;
                emptyCol = j;
            }
            else {
                board[i][j] = value--;
            }
        }
    }

    // Правило для парного розміру (Рис. 3 у завданні)
    // Потрібно поміняти місцями фішки 2 та 1
    if (size % 2 == 0) {
        // Фішка "2" знаходиться в передостанній клітинці, "1" - у третій з кінця
        // Оскільки остання (0) - це [size-1][size-1]
        int temp = board[size - 1][size - 2];
        board[size - 1][size - 2] = board[size - 1][size - 3];
        board[size - 1][size - 3] = temp;
    }
}

void GameField::display() const {
    std::cout << "\n";
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (board[i][j] == 0) {
                std::cout << std::setw(4) << "_";
            }
            else {
                std::cout << std::setw(4) << board[i][j];
            }
        }
        std::cout << "\n\n";
    }
}

void GameField::cleanup() {
    if (board != nullptr) {
        for (int i = 0; i < size; i++) delete[] board[i];
        delete[] board;
        board = nullptr;
    }
}