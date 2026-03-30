#include "raylib.h"
#include "Piece.h"
#include <vector>

const int GRID_WIDTH = 10;
const int GRID_HEIGHT = 20;
const int GRID_SIZE = 30;

int main() {
    InitWindow(GRID_WIDTH*GRID_SIZE, GRID_HEIGHT*GRID_SIZE, "Stacki Puzzle");
    SetTargetFPS(60);

    std::vector<std::vector<std::vector<bool>>> grid(GRID_HEIGHT, std::vector<std::vector<bool>>(GRID_WIDTH, std::vector<bool>(1, false)));

    std::vector<Piece> pieces = {
        Piece({{1,1,1},{0,1,0}}, RED),
        Piece({{1,1},{1,1}}, BLUE),
        Piece({{1,0},{1,1},{1,0}}, GREEN)
    };

    int score = 0;
    bool gameOver = false;

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (!gameOver) {
            for (int y = 0; y < GRID_HEIGHT; y++)
                for (int x = 0; x < GRID_WIDTH; x++)
                    if (grid[y][x][0])
                        DrawRectangle(x*GRID_SIZE, y*GRID_SIZE, GRID_SIZE-1, GRID_SIZE-1, BLACK);

            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                int x = GetMouseX()/GRID_SIZE;
                int y = GetMouseY()/GRID_SIZE;
                for (auto& p : pieces) {
                    if (p.CanPlace(grid, x, y)) {
                        p.Place(grid, x, y);
                        break;
                    }
                }
            }

            bool canPlaceAny = false;
            for (auto& p : pieces)
                for (int y = 0; y < GRID_HEIGHT; y++)
                    for (int x = 0; x < GRID_WIDTH; x++)
                        if (p.CanPlace(grid, x, y))
                            canPlaceAny = true;

            if (!canPlaceAny) gameOver = true;
        }

        DrawText(TextFormat("Score: %d", score), 10, 10, 20, BLACK);

        if (gameOver)
            DrawText("Game Over", 120, 280, 40, RED);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
