#include "ui.h"

void drawBackground(Texture2D background)
{
    DrawTexturePro(
        background,
        Rectangle{
            0,
            0,
            (float)background.width,
            (float)background.height},
        Rectangle{
            0,
            0,
            SCREEN_WIDTH,
            SCREEN_HEIGHT},
        Vector2{0, 0},
        0.0f,
        WHITE);
}

void drawUI(int score, int level, float timer)
{
    DrawText(
        TextFormat("Score : %i", score),
        90,
        10,
        30,
        WHITE);

    DrawText("Bubble Pop", 250, 250, 50, BLUE);

    DrawText(
        TextFormat("Level : %i", level),
        620,
        10,
        30,
        WHITE);

    DrawText(
        TextFormat("Time : %0.0f", timer),
        330,
        10,
        30,
        WHITE);
}

void drawBubbles(bubble bubbles[], Texture2D bubbleTexture, int currentBubble)
{
    for (int i = 0; i < currentBubble; i++)
    {
        DrawTexturePro(
            bubbleTexture,
            Rectangle{
                0,
                0,
                (float)bubbleTexture.width,
                (float)bubbleTexture.height},
            Rectangle{
                bubbles[i].x,
                bubbles[i].y,
                bubbles[i].radius * 2,
                bubbles[i].radius * 2},
            Vector2{
                bubbles[i].radius,
                bubbles[i].radius},
            0.0f,
            WHITE);
    }
}