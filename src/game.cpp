#include "game.h"

void updateLevel(float &timer, int &level, int &currentBubble, bubble bubbles[])
{
    if(timer <= 0){
    int oldBubble = currentBubble;

    currentBubble += 2;

    if(currentBubble > MAX_BUBBLE){
        currentBubble = MAX_BUBBLE;
    }
    level++;
    timer = 60;

    for(int i = oldBubble; i < currentBubble; i++){
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