#include "raylib.h"
#include "Piece.h"
#include "Table.h"
#include <vector>

int main() {
    int cellSize = 40;
    Table table(10, 10, cellSize);

    std::vector<Piece> pieces = {
        Piece({{1,1,1},{0,1,0}}, RED),
        Piece({{1,1},{1,1}}, BLUE),
        Piece({{1,0},{1,1},{1,0}}, GREEN)
    };

    InitWindow(table.GetWidth()*cellSize, table.GetHeight()*cellSize, "Stacki Puzzle");
    SetTargetFPS(60);

    bool gameOver = false;

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (!gameOver) {
            table.Draw();

            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                int x = GetMouseX() / cellSize;
                int y = GetMouseY() / cellSize;
                for (auto& p : pieces) {
                    if (table.CanPlace(p, x, y)) {
                        table.Place(p, x, y);
                        break;
                    }
                }

                if (!table.CanPlaceAny(pieces)) gameOver = true;
            }
        }

        DrawText(TextFormat("Score: %d", table.score), 10, 10, 20, BLACK);

        if (gameOver)
            DrawText("Game Over", 120, 200, 40, RED);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
