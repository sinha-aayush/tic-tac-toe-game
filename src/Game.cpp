#include "Game.h"
#include <iostream>
#include <limits>

Game::Game() : current_('X') {}

int Game::readMove() const {
    int move;
    while (true) {
        std::cout << "Player " << current_ << ", enter a position (1-9): ";
        if (std::cin >> move) {
            return move;
        }
        // Input wasn't a number: clear the error and discard the bad line
        if (std::cin.eof()) return 0;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Please type a number.\n";
    }
}

void Game::switchPlayer() {
    current_ = (current_ == 'X') ? 'O' : 'X';
}

void Game::run() {
    std::cout << "=== Tic-Tac-Toe ===\n";
    std::cout << "Positions:\n 1 | 2 | 3\n---+---+---\n 4 | 5 | 6\n---+---+---\n 7 | 8 | 9\n";

    while (!board_.isFull()) {
        board_.display();

        int move = readMove();
        if (move == 0 && std::cin.eof()) return;   // input closed (Ctrl+Z), quit

        if (!board_.place(move, current_)) {
            std::cout << "Invalid move, that spot is taken or out of range. Try again.\n";
            continue;   // same player tries again
        }
        switchPlayer();
    }

    board_.display();
    std::cout << "Board is full. Game over!\n";
}