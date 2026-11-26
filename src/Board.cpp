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

bool Board::hasWon(char mark) const {
    // All 8 winning lines, as board indices (0-8)
    static const int lines[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8},   // rows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8},   // columns
        {0, 4, 8}, {2, 4, 6}               // diagonals
    };

    for (const auto& line : lines) {
        if (cells_[line[0]] == mark &&
            cells_[line[1]] == mark &&
            cells_[line[2]] == mark) {
            return true;
        }
    }
    return false;
}