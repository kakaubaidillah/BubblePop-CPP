#include "raylib.h"
#include "bubble.h"
#include "ui.h"
#include "game.h"
#include "menu.h"
#include "input.h"
#include "gameover.h"
#include "leaderboard.h"

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
    float timer = 120.0f;
    // Menu
    GameState gameState = MENU;
    int selected = 0;
    bool enterPressed = false;

    // Player
    char playerName[21] = "";
    int letterCount = 0;
    bool finishInput = false;

    // Leaderboard
    LeaderboardData leaderboard[MAX_LEADERBOARD];
    int totalPlayer = loadLeaderboard(leaderboard);
    sortLeaderboard(leaderboard, totalPlayer);
    bool backToMenu = false;

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
            drawMenu(selected);

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

            if (finishInput)
            {
                resetGame(bubbles, currentBubble, score, level, timer);

                finishInput = false;

                gameState = PLAYING;
            }

            break;
        }

        case PLAYING:
        {
            updateTimer(timer);

            if (timer <= 0)
            {
                gameState = GAME_OVER;
                break;
            }

            updateLevel(score, level, currentBubble, bubbles);

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
            updateGameOver(enterPressed);

            if (enterPressed)
            {
                saveScore(playerName, score);
                gameState = MENU;
                enterPressed = false;
            }

            BeginDrawing();

            ClearBackground(BLACK);

            drawGameOver(playerName, score);

            EndDrawing();
            break;
        }

        case LEADERBOARD:
        {
            totalPlayer = loadLeaderboard(leaderboard);
            sortLeaderboard(leaderboard, totalPlayer);
            updateLeaderboard(backToMenu);

            if (backToMenu)
            {
                gameState = MENU;
            }

            BeginDrawing();

            ClearBackground(BLACK);

            drawLeaderboard(leaderboard, totalPlayer);

            EndDrawing();

            break;
        }
        }
    }

    UnloadTexture(background);
    UnloadTexture(bubbleTexture);

    CloseWindow();

    return 0;
}