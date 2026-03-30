#ifndef PIECE_H
#define PIECE_H

#include "raylib.h"
#include <vector>

class Piece {
public:
    std::vector<std::vector<int>> shape;
    Color color;

    Piece(std::vector<std::vector<int>> s, Color c);

    bool CanPlace(const std::vector<std::vector<std::vector<bool>>>& grid, int x, int y);
    void Place(std::vector<std::vector<std::vector<bool>>>& grid, int x, int y);
};

#endif
