#include "Piece.h"

Piece::Piece(std::vector<std::vector<int>> s, Color c) {
    shape = s;
    color = c;
}

bool Piece::CanPlace(const std::vector<std::vector<std::vector<bool>>>& grid, int x, int y) {
    int height = shape.size();
    int width = shape[0].size();
    int gridH = grid.size();
    int gridW = grid[0].size();

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (shape[i][j]) {
                int gx = x + j;
                int gy = y + i;
                if (gx < 0 || gx >= gridW || gy < 0 || gy >= gridH) return false;
                if (grid[gy][gx][0]) return false;
            }
        }
    }
    return true;
}

void Piece::Place(std::vector<std::vector<std::vector<bool>>>& grid, int x, int y) {
    int height = shape.size();
    int width = shape[0].size();
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            if (shape[i][j]) grid[y + i][x + j][0] = true;
}
