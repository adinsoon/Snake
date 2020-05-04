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
public:
    Stats();
    void countFence(bool fence);
    void countFruit(bool fruit);
    void countObstacle(bool obstacle);
    void countPoints(int howmuch, bool points);
    void countFoodEaten(bool food);
    void countunEaten(bool food);

    // currently on board
    int getFenceCountOnB() const;
    int getFruitCountOnB() const;
    int getObstacleCountOnB() const;
    int getPointsOnB() const;
    int getunEatenOnB() const;

    // total
    int getFencesTotal() const;
    int getFruitsTotal() const;
    int getObstaclesTotal() const;
    int getTotalPoints() const;
    int getTotalFoodEaten() const;
    int getTotalUneaten() const;
};


#endif //SNAKEOLD_STATS_H
