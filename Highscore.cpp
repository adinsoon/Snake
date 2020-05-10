#include "Highscore.h"
#include <iostream>


Highscore::Highscore() {

}

void Highscore::loadScores() {
    file.open("..\\highscore\\scores.txt", std::ios::in);
    if (file.good()){
        for(int j=0;j<10;j++){
            for(int i=0;i<4;i++) {
                if (i == 0) {
                    std::getline(file, line);
                    scorestr[j].points = line;
                }
                if (i == 1) {
                    std::getline(file, line);
                    scorestr[j].mins = line;
                }
                if (i == 2) {
                    std::getline(file, line);
                    scorestr[j].secs = line;
                }
                if (i == 3) {
                    std::getline(file, line);
                    scorestr[j].snake = line;
                }
            }
        }
    }
    file.close();
    for(int i=0;i<10;i++){
        scoreint[i].point = std::stoi(scorestr[i].points);
        scoreint[i].min = std::stoi(scorestr[i].mins);
        scoreint[i].sec = std::stoi(scorestr[i].secs);
        scoreint[i].size = std::stoi(scorestr[i].snake);
    }
}

/////////////////////////////////////////////////
/////     getter
void Highscore::getScore(int i, std::string &p, std::string &m, std::string &s, std::string &size) {
    p = scorestr[i].points;
    m = scorestr[i].mins;
    s = scorestr[i].secs;
    size = scorestr[i].snake;
}

/////////////////////////////////////////////////
/////     save score if it's better than any of top 10

void Highscore::saveScores(std::string point, std::string min, std::string sec, std::string s) {
    ///// conversion
    int place, intpoint, intmin, intsec, intsnake;
    intpoint = std::stoi(point);
    intmin = std::stoi(min);
    intsec = std::stoi(sec);
    intsnake = std::stoi(s);
    ///// comparison
    for(int i=0;i<10;i++){
        // to points
        if(scoreint[i].point < intpoint) {
            place = i;
            break;
        }
        else if(scoreint[9].point > intpoint) {
            place = -1;
            break;
        }
        else if (scoreint[i].point == intpoint){
            // to minutes
            if(scoreint[i].min > intmin) {
                place = i;
                break;
            }
            else if(scoreint[i].min == intmin){
                // to seconds
                if(scoreint[i].sec > intsec) {
                    place = i;
                    break;
                }
                else if(scoreint[i].sec == intsec){
                    // to size
                    if(scoreint[i].size < intsnake) {
                        place = i;
                        break;
                    }
                    else if(scoreint[i].size == intsnake) {
                        place = -1;
                        break;
                    }
                }
            }
        }
    }
    if(place != -1){
        scorestr[place].points = point;
        scorestr[place].mins = min;
        scorestr[place].secs = sec;
        scorestr[place].snake = s;
    }
    file.open("..\\highscore\\scores.txt", std::ios::out);
    if (file.good()){
        for(int i=0;i<10;i++){
            file<<scorestr[i].points<<std::endl;
            file<<scorestr[i].mins<<std::endl;
            file<<scorestr[i].secs<<std::endl;
            file<<scorestr[i].snake<<std::endl;
        }
    }
    file.close();
}
