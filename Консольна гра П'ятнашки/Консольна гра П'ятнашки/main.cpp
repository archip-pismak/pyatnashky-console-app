#include <iostream>
#include <Windows.h> // Для виправлення символів '?' в консолі
#include "game.h"

int main() {
    // Налаштування української мови в консолі
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int userSize;
    std::cout << "ПРАКТИЧНА РОБОТА 4: Гра «П'ятнашки»\n";
    std::cout << "Введіть бажаний розмір поля (" << MIN_SIZE << "-" << MAX_SIZE << "): ";
    std::cin >> userSize;

    // Перевірка допустимості розміру
    if (userSize < MIN_SIZE || userSize > MAX_SIZE) {
        std::cout << "Помилка! Розмір має бути в межах від 3 до 9.\n";
        return 1;
    }

    GameController myGame;

    // Ініціалізація каркаса програми
    initGame(myGame, userSize);

    std::cout << "Поле " << userSize << "x" << userSize << " успішно створено динамічно!\n";

    // Вивід порожнього поля (демонстрація роботи структури)
    displayField(myGame.field);

    std::cout << "\nКаркас програми завершив роботу.\n";

    // Обов'язкове звільнення пам'яті
    cleanup(myGame.field);

    return 0;
}