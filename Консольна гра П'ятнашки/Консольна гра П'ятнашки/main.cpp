#include <iostream>
#include <Windows.h>
#include "game.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int d;
    std::cout << "Введіть розмір поля (3-9): ";
    std::cin >> d;

    if (d < MIN_SIZE || d > MAX_SIZE) {
        std::cout << "Некоректний розмір!\n";
        return 1;
    }

    GameField myField;
    myField.init(d);
    myField.display();

    std::cout << "Поле успішно ініціалізовано за правилом (зворотний порядок).\n";

    myField.cleanup();
    return 0;
}