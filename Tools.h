#ifndef SNAKEOLD_TOOLS_H
#define SNAKEOLD_TOOLS_H
#include "Board.h"
#include "Stats.h"
#include "GameLogic.h"
#include <string>

class Tools {
    Board &board;
    Stats &stats;
    GameLogic &logic;
public:
    Tools(Board &b1, Stats &s1, GameLogic &c1);

    ///// use alone only when needed - putters
    void putFence(int row, int col);
    void putFruit(int row, int col);
    void putObstacle(int row, int col);

    ///// create walls around
    void fenceFill();

    ///// use alone only when needed - takers
    void takeFence(int row, int col);
    void takeFruit(int row, int col);
    void takeObstacle(int row, int col);

    ///// spawn section
    void fixedSpawn(std::string what, int x, int y);
    void randomSpawn(std::string what);

    ///// diagnostic info
    void getGameInfo() const;

    ///// view
    char getFieldInfo(int row, int col) const;

    ///// debug section
    void debug_display() const;
};


#endif //SNAKEOLD_TOOLS_H
