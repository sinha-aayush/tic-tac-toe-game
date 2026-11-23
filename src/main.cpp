#include "Board.h"

int main() {
    Board board;
    board.place(1, 'X');
    board.place(5, 'O');
    board.display();
    return 0;
}