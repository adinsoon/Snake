#ifndef SNAKEOLD_STATS_H
#define SNAKEOLD_STATS_H

class Stats {
    int fruitCount=0;
    int fenceCount=0;
    int obstacleCount=0;
    int pointsCount=0;
    int foodEaten=0;
public:
    Stats();
    void countFence(bool fence);
    void countFruit(bool fruit);
    void countObstacle(bool obstacle);
    void countPoints(int howmuch, bool points);
    void countFoodEaten();

    int getFenceCount() const;
    int getFruitCount() const;
    int getObstacleCount() const;
    int getPoints() const;
    int getFoodEaten() const;
};


#endif //SNAKEOLD_STATS_H
