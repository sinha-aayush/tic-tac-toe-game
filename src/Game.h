#pragma once
#include "Board.h"

class Game {
public:
    Game();
    void push();

private:
    Board board_;
    char current_;

    int readMove() const;
    void switchPlayer();
};