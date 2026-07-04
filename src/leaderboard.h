#pragma once

#include <string>

const int MAX_LEADERBOARD = 10;

struct LeaderboardData{
    std::string name;
    int score;
    char space;
};

void saveScore(const char playerName[], int score);
int loadLeaderboard(LeaderboardData data[]);
void sortLeaderboard(LeaderboardData data[], int total);
void drawLeaderboard(LeaderboardData data[], int total);
void updateLeaderboard(bool &backToMenu);