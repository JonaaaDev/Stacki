#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

class GameManager {
public:
    // Variables de puntuación ajustables
    int pointsPerCompletedLine;
    int comboBaseBonus;
    int comboExtraMultiplier;

    GameManager();

    int CalculateLineClearScore(int completedLines) const;
};

#endif
