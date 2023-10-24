#ifndef SOLVER_HPP_
#define SOLVER_HPP_

#include <SFML/Graphics.hpp>

#include <iostream>
#include <cstdlib>
#include <thread>
#include <random>
#include <vector>
#include <ctime>

bool isValid(int, int, int, std::vector<std::vector<int>>&);
void drawBoard(sf::RenderWindow&, std::vector<std::vector<int>>&, const std::vector<int>&, const std::vector<int>&);
void solveKnightTour(int, int, std::vector<std::vector<int>>&, const std::vector<int>&, const std::vector<int>&);

#endif //SOLVER_HPP_
