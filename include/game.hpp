#ifndef EKSAMEN_2023_GAME_HPP
#define EKSAMEN_2023_GAME_HPP

#pragma once

#include <random>
#include "grid.hpp"
#include "../src/blocks.cpp"

class Game {
public:
    Game();
    Block GetRandomBlock();
    static std::vector<Block> GetAllBlocks();
    void Update(threepp::Scene &scene, float deltaTime);
    void Draw(threepp::Scene &scene);
    void moveCurrentBlock(int rows, int columns);
    void RotateBlock();
    bool IsBlockOutside(const Block &block, int rows, int columns);
    const float blockFallInterval = 1.0f; // Adjust the value based on your preference
    float elapsedSinceLastFall = 0.0f;
    Grid grid;

private:
    std::vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;
    std::random_device rd;
    std::mt19937 gen;
    bool IsCollision(const Block &block, int rows, int columns);


};

#endif // EKSAMEN_2023_GAME_HPP

