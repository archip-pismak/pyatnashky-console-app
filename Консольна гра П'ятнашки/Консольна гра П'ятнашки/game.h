#ifndef GAME_H
#define GAME_H

#define MIN_SIZE 3
#define MAX_SIZE 9

// Перелічення для стану гри
enum GameState { ACTIVE, WIN, ABORTED };

struct GameField {
    int** board;
    int size;
    int emptyRow;
    int emptyCol;
    GameState status;

    // Функції-члени
    void init(int d);
    void display() const;
    bool checkMove(int r, int c) const;
    void makeMove(int tileNumber);
    bool checkWin() const;
    void cleanup(); // Метод для звільнення пам'яті
};

struct GameController {
    GameField field;
    int movesCount;

    // Функції-члени
    void startGame();
    int handleInput() const;
    void gameLoop();
};

#endif