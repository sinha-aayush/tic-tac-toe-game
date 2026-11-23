#include "Board.h"
#include <iostream>

Board::Board() {
    cells_.fill(' ');
}

void Board::display() const {
    std::cout << "\n";
    for (int row = 0; row < 3; ++row) {
        std::cout << " ";
        for (int col = 0; col < 3; ++col) {
            std::cout << cells_[row * 3 + col];
            if (col < 2) std::cout << " | ";
        }
        std::cout << "\n";
        if (row < 2) std::cout << "---+---+---\n";
    }
    std::cout << "\n";
}

bool Board::place(int position, char mark) {
    int index = position - 1;
    if (index < 0 || index > 8 || cells_[index] != ' ') return false;
    cells_[index] = mark;
    return true;
}

bool Board::isFull() const {
    for (char c : cells_) {
        if (c == ' ') return false;
    }
    return true;
}