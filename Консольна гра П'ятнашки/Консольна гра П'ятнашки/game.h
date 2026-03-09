#ifndef GAME_H
#define GAME_H

// Макроси для запобігання "magic numbers"
#define MIN_SIZE 3
#define MAX_SIZE 9

// Структура для зберігання ігрового поля
struct GameField {
    int** cells;       // Динамічний двовимірний масив для фішок
    int size;          // Поточний розмір поля (N x N)
    int emptyRow;      // Позиція порожньої клітинки (рядок)
    int emptyCol;      // Позиція порожньої клітинки (стовпець)
};

// Структура для керування ігровим процесом
struct GameController {
    GameField field;   // Об'єкт поля
    int movesCount;    // Кількість зроблених ходів
    bool isRunning;    // Статус гри
};

// Прототипи основних функціональних можливостей
void initGame(GameController& controller, int size);
void displayField(const GameField& field);
void cleanup(GameField& field);

#endif