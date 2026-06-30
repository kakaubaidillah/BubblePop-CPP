#pragma once

#include "raylib.h"
#include "bubble.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

void drawBackground(Texture2D background);
void drawUI(int score, int level, float timer);
void drawBubbles(bubble b[], Texture2D bubbleTexture, int currentBubble);