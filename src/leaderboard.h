#pragma once

#include <string>

struct LeaderboardData{
    std::string nama;
    int score;
};

void saveScore(const char playerName[], int score);
int loadLeaderboard(LeaderboardData data[]);