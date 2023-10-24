#include <SFML/Graphics.hpp>

#include <iostream>
#include <cstdlib>
#include <thread>
#include <random>
#include <vector>
#include <ctime>

#include "Solver.hpp"

int main() {
    int chessboardSize;
    std::cout << "Enter the size of the chessboard: ";
    std::cin >> chessboardSize;
    if (chessboardSize < 4 || chessboardSize > 16) {
        std::cerr << "Invalid chessboard size. Please enter an integer from this range [4, 16]." << std::endl;
        return 1;
    }
    std::vector<int> moveX = {2, 1, -1, -2, -2, -1, 1, 2};
    std::vector<int> moveY = {1, 2, 2, 1, -1, -2, -2, -1};
    sf::RenderWindow window(sf::VideoMode(chessboardSize * 60, chessboardSize * 60), "Knight's Tour");
    std::vector<std::vector<int>> board(chessboardSize, std::vector<int>(chessboardSize, -1));
    int startX = std::random_device()() % chessboardSize;
    int startY = std::random_device()() % chessboardSize;
    board[startY][startX] = 0;
    std::thread knightTourThread(solveKnightTour, startX, startY, std::ref(board), moveX, moveY);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        drawBoard(window, board, moveX, moveY);
    }
    knightTourThread.detach();
}

