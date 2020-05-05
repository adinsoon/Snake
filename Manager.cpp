#include "Manager.h"

int Manager::getGame() const {
    return gameHandler;
}

void Manager::setGame(int g) {
    gameHandler = g;
}

Manager::Manager() {
    gameHandler = 0;
}
