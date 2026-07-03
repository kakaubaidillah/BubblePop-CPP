#include "input.h"
#include "raylib.h"

void updateInputName(char name[], int &letterCount, bool &finishInput){
    int key = GetCharPressed();

    while(key > 0){
        if((key >= 32) && (key <= 125) && letterCount < 20){
            name[letterCount] = (char)key;
            letterCount++;
            name[letterCount] = '\0';
        }
        key = GetCharPressed();
    }
        
    if(IsKeyPressed(KEY_BACKSPACE) && letterCount > 0){
            letterCount--;
            name[letterCount] = '\0';
    }
    if(IsKeyPressed(KEY_ENTER) && letterCount > 0){
            finishInput = true;
    }
    
}

void drawInputName(char name[]){
    DrawText(
        "ENTER YOUR NAME",
        220,
        150,
        40,
        WHITE
    );

    DrawRectangleLines(
        200,
        250,
        400,
        50,
        WHITE
    );

    DrawText(
        name,
        215,
        260,
        30,
        YELLOW
    );

    DrawText(
        "Press ENTER to Continue",
        220,
        340,
        20,
        LIGHTGRAY
    );
}