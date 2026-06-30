#include "bubble.h"

#include <cstdlib>
#include <cmath>

void spawnBubble(bubble &b)
{
    b.x = rand() % 700 + 50;
    b.y = rand() % 500 + 50;
    b.speed = 1 + rand() % 3;
    b.waveOffset = rand() % 360;
    b.radius = 20 + rand() % 31;
}

void updateBubbles(bubble b[], int currentBubble)
{
    for (int i = 0; i < currentBubble; i++)
    {
        b[i].y -= b[i].speed;
        b[i].waveOffset += 0.05f;
        b[i].x += sin(b[i].waveOffset);

        if (b[i].y < -50)
        {
            spawnBubble(b[i]);
        }
    }
}

void bubbleClick(bubble b[], int &score, int currentBubble)
{
    Vector2 mousePos = GetMousePosition(); //----------------ambil posisi maouse

    //---Deteksi Klik Bubble
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        for (int i = 0; i < currentBubble; i++)
        {
            if (CheckCollisionPointCircle(
                    mousePos,
                    Vector2{
                        b[i].x,
                        b[i].y},
                    b[i].radius))
            {
                if (b[i].radius < 30)
                {
                    score += 3;
                }
                else
                {
                    score += 1;
                }
                spawnBubble(b[i]);
            }
        }
    }
}