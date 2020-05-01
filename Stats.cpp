#include "Stats.h"


Stats::Stats() {

}

void Stats::countFence(bool fence) {
    if(fence)
        fenceCount++;
    else fenceCount--;
}

void Stats::countFruit(bool fruit) {
    if(fruit)
        fruitCount++;
    else fruitCount--;
}

void Stats::countObstacle(bool obstacle) {
    if(obstacle)
        obstacleCount++;
    else obstacleCount--;
}

void Stats::countPoints(int howmuch, bool points) {
    if(points) {
        pointsCount += howmuch;
    }
    else pointsCount -= howmuch;
}

int Stats::getPoints() const {
    return pointsCount;
}

int Stats::getFruitCount() const {
    return fruitCount;
}

int Stats::getFenceCount() const {
    return fenceCount;
}

int Stats::getObstacleCount() const {
    return obstacleCount;
}

void Stats::countFoodEaten() {
    foodEaten++;
}

int Stats::getFoodEaten() const {
    return foodEaten;
}


