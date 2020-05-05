#include "Stats.h"


Stats::Stats() {
    ///// [0] - currently on Board  [1] - total
    for(int i=0;i<2;i++) {
        fruitsCount[i] = 0;
        fencesCount[i] = 0;
        obstaclesCount[i] = 0;
        foodCount[i] = 0;
        unEatenCount[i]=0;
    }
    pointsEarned = 0;
    gameSeconds = 0;
    gameMinutes = 0;
}

///// COUNT BOTH

void Stats::countFruit(bool fruit) {
    if(fruit) {
        fruitsCount[0]++;
        fruitsCount[1]++;
    }
    else
        fruitsCount[0]--;
}

void Stats::countFence(bool fence) {
    if(fence) {
        fencesCount[0]++;
        fencesCount[1]++;
    }
    else fencesCount[0]--;
}

void Stats::countObstacle(bool obstacle) {
    if (obstacle) {
        obstaclesCount[0]++;
        obstaclesCount[1]++;
    }
    else obstaclesCount[0]--;
}

void Stats::countFoodEaten(bool food) {
    if(food) {
        foodCount[0]++;
        foodCount[1]++;
    }
    else foodCount[0]--;
}

void Stats::countPoints(bool points) {
    if(points) {
        pointsEarned += howmuch;
    }
    else pointsEarned -= howmuch;
}

void Stats::countUnEaten(bool food) {
    if(food) {
        unEatenCount[0]++;
        unEatenCount[1]++;
    }
    else {
        unEatenCount[0]--;
        unEatenCount[1]--;
    }
}

///// GET ON BOARD

int Stats::getFruitCountOnB() const {
    return fruitsCount[0];
}

int Stats::getFenceCountOnB() const {
    return fencesCount[0];
}

int Stats::getObstacleCountOnB() const {
    return obstaclesCount[0];
}

int Stats::getPointsOnB() const{
    return foodCount[0];
}

int Stats::getUnEatenOnB() const {
    return unEatenCount[0];
}

///// GET TOTAL

int Stats::getFruitsTotal() const {
    return fruitsCount[1];
}

int Stats::getFencesTotal() const {
    return fencesCount[1];
}

int Stats::getObstaclesTotal() const {
    return obstaclesCount[1];
}

int Stats::getTotalFoodEaten() const {
    return foodCount[1];
}

int Stats::getTotalPoints() const {
    return pointsEarned;
}

int Stats::getTotalUneaten() const {
    return unEatenCount[1];
}

void Stats::setGameMinutes(int m) {
    gameMinutes += m;
}

void Stats::setGameSeconds(int s) {
    gameSeconds += s;
}

void Stats::setRemaining(int h) {
    remaining += h;
}

int Stats::getGameMinutes() const {
    return gameMinutes;
}

int Stats::getGameSeconds() const {
    return gameSeconds;
}

int Stats::getRemaining() const {
    return remaining;
}

void Stats::setPointsRate(int q) {
    howmuch = q;
}

int Stats::getPointsRate() const {
    return howmuch;
}
