#include "leaderboard.h"

#include <fstream>
#include <string>

void saveScore(const char playerName[], int score);
int loadLeaderboard(LeaderboardData data[]);