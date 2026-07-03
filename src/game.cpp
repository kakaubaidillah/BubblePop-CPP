#include "game.h"

void updateLevel(int score, int &level, int &currentBubble, bubble bubbles[])
{
    int targetBubble = currentBubble;

    if(score >= 100)
    {
        level = 4;
        targetBubble = 11;
    }
    else if(score >= 50)
    {
        level = 3;
        targetBubble = 9;
    }
    else if(score >= 20)
    {
        level = 2;
        targetBubble = 7;
    }
    else
    {
        level = 1;
        targetBubble = 5;
    }

    if(targetBubble > currentBubble)
    {
        int oldBubble = currentBubble;
        currentBubble = targetBubble;

        for(int i = oldBubble; i < currentBubble; i++)
        {
            spawnBubble(bubbles[i]);
        }
    }
}

void updateTimer(float &timer)
{
    timer -= GetFrameTime();

    if (timer < 0)
    {
        timer = 0;
    }
}

void resetGame(bubble bubbles[], int &currentBubble, int &score, int &level, float &timer){
    score = 0;
    level = 1;
    timer = 120.0f;
    currentBubble = 5;

    for(int i = 0; i < currentBubble; i++){
        spawnBubble(bubbles[i]);
    }
}