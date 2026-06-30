#include "raylib.h"
#include "bubble.h"
#include "ui.h"
#include "game.h"
#include "menu.h"
#include "input.h"

#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Bubble Pop");
    bubble bubbles[MAX_BUBBLE];
    // int bubbleRadius = 40;

    // GamePlay
    int currentBubble = 5;
    int score = 0;
    int level = 1;
    float timer = 60.0f;
    // Menu
    GameState gameState = MENU;
    int selected = 0;
    bool enterPressed = false;

    // Player
    char playerName[21] = "";
    int letterCount = 0;
    bool finishInput = false;

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
        switch (gameState)
        {
        case MENU:
        {
            updateMenu(selected, enterPressed);

            if (enterPressed)
            {
                if (selected == 0)
                {
                    gameState = INPUT_NAME;

                    enterPressed = false;
                    letterCount = 0;
                    playerName[0] = '\0';
                }
                else if (selected == 1)
                {
                    gameState = LEADERBOARD;

                    enterPressed = false;
                }
                else if (selected == 2)
                {
                    CloseWindow();
                }
                enterPressed = false;
            }

            BeginDrawing();

            ClearBackground(BLACK);
            drawMenu();

            EndDrawing();
            break;
        }

        case INPUT_NAME:
        {
            updateInputName(playerName, letterCount, finishInput);

            BeginDrawing();

            ClearBackground(SKYBLUE);

            drawInputName(playerName);

            EndDrawing();


            if(finishInput)
            {
                gameState = PLAYING;
            }

            break;
        }

        case PLAYING:
        {
            // INI GAME KAMU YANG LAMA

            updateTimer(timer);

            updateLevel(timer, level, currentBubble, bubbles);

            updateBubbles(bubbles, currentBubble);

            bubbleClick(bubbles, score, currentBubble);

            BeginDrawing();

            drawBackground(background);

            drawUI(score, level, timer);

            drawBubbles(bubbles, bubbleTexture, currentBubble);

            EndDrawing();

            break;
        }

        case GAME_OVER:
        {
            // nanti
            break;
        }

        case LEADERBOARD:
        {
            // nanti
            break;
        }
        }
    }

    UnloadTexture(background);
    UnloadTexture(bubbleTexture);

    CloseWindow();

    return 0;
}