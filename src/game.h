#pragma once

#include "raylib.h"
#include "bubble.h"
#include <ctime>

enum GameState{
    MENU,
    INPUT_NAME,
    PLAYING,
    GAME_OVER,
    LEADERBOARD
};

void updateLevel(int score, int &level, int &currentBubble, bubble bubbles[]);
void updateTimer(float &timer);
void resetGame(bubble bubbles[], int &currentBubble, int &score, int &level, float &timer);