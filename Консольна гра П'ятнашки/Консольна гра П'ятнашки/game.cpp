#include "game.h"
#include <iostream>
#include <iomanip> // Для красивого виводу таблиці

void initGame(GameController& controller, int size) {
    controller.field.size = size;
    controller.movesCount = 0;
    controller.isRunning = true;

    // 1. Виділення пам'яті під масив вказівників (рядки)
    controller.field.cells = new int* [size];
    for (int i = 0; i < size; i++) {
        // 2. Виділення пам'яті під кожен рядок (стовпці)
        controller.field.cells[i] = new int[size];
    }

    // Тимчасове заповнення поля нулями (для каркаса)
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            controller.field.cells[i][j] = 0;
        }
    }
}

void displayField(const GameField& field) {
    std::cout << "\n--- ІГРОВЕ ПОЛЕ ---\n";
    for (int i = 0; i < field.size; i++) {
        for (int j = 0; j < field.size; j++) {
            // Виводимо числа, вирівнюючи їх по ширині
            std::cout << std::setw(3) << field.cells[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "-------------------\n";
}

void cleanup(GameField& field) {
    // Звільнення пам'яті у зворотному порядку
    if (field.cells != nullptr) {
        for (int i = 0; i < field.size; i++) {
            delete[] field.cells[i];
        }
        delete[] field.cells;
        field.cells = nullptr;
    }
}