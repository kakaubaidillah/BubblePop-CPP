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

void updateLevel(float &timer, int &level, int &currentBubble, bubble bubbles[]);
void updateTimer(float &timer);