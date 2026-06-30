#include "menu.h"

void drawMenu()
{
    DrawText("BUBBLE POP", 250, 120, 50, BLUE);

    DrawText("PLAY",         330, 250, 30, WHITE);
    DrawText("LEADERBOARD",  270, 300, 30, WHITE);
    DrawText("EXIT",         335, 350, 30, WHITE);
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