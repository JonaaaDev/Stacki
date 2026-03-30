#include "GameManager.h"

GameManager::GameManager() {
    pointsPerCompletedLine = 100;
    comboBaseBonus = 50;
    comboExtraMultiplier = 25;
}

int GameManager::CalculateLineClearScore(int completedLines) const {
    if (completedLines <= 0) return 0;

    int score = completedLines * pointsPerCompletedLine;

    if (completedLines > 1) {
        int comboSize = completedLines - 1;
        score += comboBaseBonus * comboSize;
        score += comboExtraMultiplier * comboSize * comboSize;
    }

    return score;
}
