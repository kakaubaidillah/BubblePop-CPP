#include "raylib.h"
#include "gameover.h"

void drawGameOver(const char playerName[], int score){
    DrawText("GAME OVER", 250, 120, 50, RED);

    DrawText(
        TextFormat("Player : %s", playerName),
        220,
        230,
        30,
        WHITE);

    DrawText(
        TextFormat("Score : %i", score),
        220,
        280,
        30,
        WHITE);

    DrawText(
        "Press ENTER",
        260,
        380,
        25,
        YELLOW);
}

void updateGameOver(bool &enterPressed){
    enterPressed = IsKeyPressed(KEY_ENTER);
}