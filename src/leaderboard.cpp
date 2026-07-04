#include "leaderboard.h"
#include "raylib.h"

#include <fstream>
#include <string>

void saveScore(const char playerName[], int score){
    std::ofstream file("data/leaderboard.txt", std:: ios::app);
    if(file.is_open()){

        file << playerName << " " << score << std::endl;
        file.close();
    }else{
        printf("FILE TIDAK DITEMUKAN!!\n");
    }
}

int loadLeaderboard(LeaderboardData data[]){
    std::ifstream file("data/leaderboard.txt");

    int total = 0;

    if(file.is_open()){
        while(file >> data[total].name >> data[total].score){
            total++;
            if(total == MAX_LEADERBOARD){
                break;
            }
        }
        file.close();
    }
    return total;
}

void sortLeaderboard(LeaderboardData data[], int total){
    for(int i = 0; i < total - 1; i++){
        for(int j = i + 1; j < total; j++){
            if(data[j].score > data[i].score){
                std::swap(data[i], data[j]);
            }
        }
    }
}

void drawLeaderboard(LeaderboardData data[], int total){
    DrawText("LEADERBOARD", 240, 70, 40, YELLOW);

    DrawText("Rank", 120, 150, 25, WHITE);
    DrawText("Name", 260, 150, 25, WHITE);
    DrawText("Score", 560, 150, 25, WHITE);

    for(int i = 0; i < total; i++){
        DrawText(TextFormat("%d", i + 1), 130, 200 + i * 40, 25, WHITE);
        DrawText(data[i].name.c_str(), 260, 200 + i * 40, 25, SKYBLUE);
        DrawText(TextFormat("%d", data[i].score), 570, 200 + i * 40, 25, GREEN);
    }
    DrawText("Press ESC to return", 240, 540, 20, LIGHTGRAY);
}

void updateLeaderboard(bool &backToMenu){
    backToMenu = false;

    if(IsKeyPressed(KEY_ENTER)){
        backToMenu = true;
    }
}