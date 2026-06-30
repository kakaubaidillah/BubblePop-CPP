#pragma once

#include "raylib.h"

const int MAX_BUBBLE = 50;

struct bubble
{
    float x;
    float y;
    float speed;
    float waveOffset;
    float radius;
};

void spawnBubble(bubble &b);
void updateBubbles(bubble b[], int currentBubble);
void bubbleClick(bubble b[], int &score, int currentBubble);