#include "raylib.h"
#include "bubble.h"
#include "ui.h"
#include "game.h"
#include "menu.h"

#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>


int main()
{
    GameState gameState = MENU;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Bubble Pop");
    bubble bubbles[MAX_BUBBLE];
    // int bubbleRadius = 40;

    int selected = 0;
    bool enterPressed = false;
    int currentBubble = 5;
    int score = 0;
    int level = 1;
    float timer = 60.0f;

    Texture2D background = LoadTexture("assets/bg02.png");
    if (background.id == 0)
    {
        printf("background Fail to Load!!\n");
    }
    Texture2D bubbleTexture = LoadTexture("assets/bubble.png");
    if (bubbleTexture.id == 0)
    {
        printf("bubbleTexture Fail to Load!!\n");
    }

    srand(time(NULL));

    for (int i = 0; i < currentBubble; i++)
    {
        spawnBubble(bubbles[i]);
    }

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        
    }

    UnloadTexture(background);
    UnloadTexture(bubbleTexture);

    CloseWindow();

    return 0;
}