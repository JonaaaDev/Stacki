#ifndef TABLE_H
#define TABLE_H

#include "Piece.h"
#include "GameManager.h"
#include "raylib.h"
#include <vector>

struct Cell {
    bool filled = false;
    Color color = RAYWHITE;
};

class Table {
private:
    int width;
    int height;
    int cellSize;
    std::vector<std::vector<Cell>> grid;
    GameManager gameManager;

public:
    int score;

    Table(int w = 10, int h = 10, int size = 30);

    bool CanPlace(Piece& piece, int x, int y);
    void Place(Piece& piece, int x, int y);
    int CheckLines();
    bool CanPlaceAny(std::vector<Piece>& pieces);
    void Draw();
};

#endif
