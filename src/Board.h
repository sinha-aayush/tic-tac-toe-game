#pragma once

class Board {
public:
    Board();
    void display() const;
    bool place(int position, char mark); 
    bool isFull() const;
    char at(int index) const { return cells_[index]; }

private:
    std::array<char, 9> cells_;
};