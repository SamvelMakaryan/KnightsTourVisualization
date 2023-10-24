#include <SFML/Graphics.hpp>

#include <iostream>
#include <cstdlib>
#include <thread>
#include <random>
#include <vector>
#include <ctime>

bool isValid(int x, int y, int N, std::vector<std::vector<int>>& board) {
    return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1);
}

void drawBoard(sf::RenderWindow& window, std::vector<std::vector<int>>& board, const std::vector<int>& dx, const std::vector<int>& dy) {
    float cellSize = 60.0f;
    sf::VertexArray lines(sf::LinesStrip);
    for (int i = 0; i < board.size() * board[0].size(); ++i) {
        for (int j = 0; j < board.size(); ++j) {
            for (int k = 0; k < board[0].size(); ++k) {
                if (board[j][k] == i) {
                    float x = k * cellSize + cellSize / 2;
                    float y = j * cellSize + cellSize / 2;
                    lines.append(sf::Vertex(sf::Vector2f(x, y), sf::Color::Red));
                    break;
                }
            }
        }
    }
    window.clear();
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j) {
            sf::RectangleShape square(sf::Vector2f(cellSize, cellSize));
            square.setPosition(j * cellSize, i * cellSize);
            if ((i + j) % 2 == 0) {
                square.setFillColor(sf::Color::White);
            } else {
                square.setFillColor(sf::Color(129, 133, 137));
            }
            window.draw(square);
        }
    }
    window.draw(lines);
    window.display();
}

void solveKnightTour(int startX, int startY, std::vector<std::vector<int>>& board, const std::vector<int>& dx, const std::vector<int>& dy) {
    int N = board.size();
    int x = startX;
    int y = startY;
    int move = 1;
    while (move < N * N) {
        std::vector<std::pair<int, int>> moves;
        for (int i = 0; i < 8; i++) {
            int nextX = x + dx[i];
            int nextY = y + dy[i];
            if (isValid(nextX, nextY, N, board)) {
                int count = 0;
                for (int j = 0; j < 8; j++) {
                    int next2X = nextX + dx[j];
                    int next2Y = nextY + dy[j];
                    if (isValid(next2X, next2Y, N, board)) {
                        count++;
                    }
                }
                moves.push_back({count, i});
            }
        }
        if (moves.empty()) {
            break;
        }
        std::sort(moves.begin(), moves.end());
        int nextX = x + dx[moves[0].second];
        int nextY = y + dy[moves[0].second];
        board[nextX][nextY] = move;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        x = nextX;
        y = nextY;
        ++move;
    }
}
