#include "menu.h"

void drawMenu(int selected)
{
    DrawText("BUBBLE POP", 250, 120, 50, BLUE);

    DrawText(selected == 0 ? "> PLAY" : " PLAY", 300, 250, 30, WHITE);
    DrawText(selected == 1 ? "> LEADERBOARD" : " LEADERBOARD",  270, 300, 30, WHITE);
    DrawText(selected == 2 ? "> EXIT" : " EXIT", 335, 350, 30, WHITE);
}

void updateMenu(int &selected, bool &enterPressed)
{
    enterPressed = false;

    if (IsKeyPressed(KEY_DOWN))
        selected++;

    if (IsKeyPressed(KEY_UP))
        selected--;

    if (selected < 0)
        selected = 2;

    if (selected > 2)
        selected = 0;

    if (IsKeyPressed(KEY_ENTER))
        enterPressed = true;
}