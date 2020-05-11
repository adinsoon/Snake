#ifndef SNAKEOLD_STATS_H
#define SNAKEOLD_STATS_H
#include <vector>

class Stats {
    ///// [0] - currently on Board  [1] - total
    int fencesCount[2];
    int fruitsCount[2];
    int obstaclesCount[2];
    int foodCount[2];
    int unEatenCount[2];

    int pointsEarned;

    ////////// AFTER GAME - TO SCOREBOARD
    int gameMinutes;
    int gameSeconds;
    int remaining;

    int howmuch=20;
public:
    Stats();
    void countFence(bool fence);
    void countFruit(bool fruit);
    void countObstacle(bool obstacle);
    void countPoints(bool points);
    void countFoodEaten(bool food);
    void countUnEaten(bool food);
    void setPointsRate(int q);
    int getPointsRate() const;

    // currently on board
    int getFenceCountOnB() const;
    int getFruitCountOnB() const;
    int getObstacleCountOnB() const;
    int getPointsOnB() const;
    int getUnEatenOnB() const;

    // total
    int getFencesTotal() const;
    int getFruitsTotal() const;
    int getObstaclesTotal() const;
    int getTotalFoodEaten() const;
    int getTotalUneaten() const;

    int getTotalPoints() const;

    // AFTER GAME - TO SCOREBOARD
    void setGameMinutes(int m);
    void setGameSeconds(int s);
    void setRemaining(int h);
    int getGameMinutes() const;
    int getGameSeconds() const;
    int getRemaining() const;
};


#endif //SNAKEOLD_STATS_H
