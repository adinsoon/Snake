#ifndef SNAKEOLD_HIGHSCORE_H
#define SNAKEOLD_HIGHSCORE_H
#include <iostream>
#include <fstream>
#include <string>

struct text {
    std::string points;
    std::string mins;
    std::string secs;
    std::string snake;
};

struct number {
    int point;
    int min;
    int sec;
    int size;
};

class Highscore {
    std::fstream file;

    int playerNo=0;
    int lineNo=1;
    std::string line;

    text scorestr[10];
    number scoreint[10];
public:
    Highscore();

    void loadScores();

    void getScore(int i, std::string &p, std::string &m, std::string &s, std::string &size);

    void saveScores(std::string point, std::string min, std::string sec, std::string s);
};


#endif //SNAKEOLD_HIGHSCORE_H
