#include "Table.h"

Table::Table(int w, int h, int size) {
    width = w;
    height = h;
    cellSize = size;
    score = 0;
    grid.resize(height, std::vector<Cell>(width));
}

bool Table::CanPlace(Piece& piece, int x, int y) {
    int ph = piece.shape.size();
    int pw = piece.shape[0].size();
    for (int i = 0; i < ph; i++) {
        for (int j = 0; j < pw; j++) {
            if (piece.shape[i][j]) {
                int gx = x + j;
                int gy = y + i;
                if (gx < 0 || gx >= width || gy < 0 || gy >= height) return false;
                if (grid[gy][gx].filled) return false;
            }
        }
    }
    return true;
}

void Table::Place(Piece& piece, int x, int y) {
    int ph = piece.shape.size();
    int pw = piece.shape[0].size();
    for (int i = 0; i < ph; i++)
        for (int j = 0; j < pw; j++)
            if (piece.shape[i][j]) {
                grid[y+i][x+j].filled = true;
                grid[y+i][x+j].color = piece.color;
            }
    score += CheckLines();
}

int Table::CheckLines() {
    int points = 0;
    // horizontal
    for (int y = 0; y < height; y++) {
        bool full = true;
        for (int x = 0; x < width; x++)
            if (!grid[y][x].filled) full = false;
        if (full) {
            points++;
            for (int x = 0; x < width; x++)
                grid[y][x].filled = false;
        }
    }
    // vertical
    for (int x = 0; x < width; x++) {
        bool full = true;
        for (int y = 0; y < height; y++)
            if (!grid[y][x].filled) full = false;
        if (full) {
            points++;
            for (int y = 0; y < height; y++)
                grid[y][x].filled = false;
        }
    }
    return points;
}

bool Table::CanPlaceAny(std::vector<Piece>& pieces) {
    for (auto& p : pieces)
        for (int y = 0; y < height; y++)
            for (int x = 0; x < width; x++)
                if (CanPlace(p, x, y)) return true;
    return false;
}

void Table::Draw() {
    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++)
            if (grid[y][x].filled)
                DrawRectangle(x*cellSize, y*cellSize, cellSize-1, cellSize-1, grid[y][x].color);
}
