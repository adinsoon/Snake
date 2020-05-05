#include <iostream>
#include "Board.h"
#include "Tools.h"
#include "Stats.h"
#include "Logic.h"
#include "Controller.h"
#include "TextView.h"
#include "SFMLView.h"
#include "SFMLController.h"
#include "Menu.h"
#include "Manager.h"
#include "PostGame.h"
#include <fstream>

using namespace std;

void GameHandler(){

}

int main() {
    Manager mgr;
    do {
        Menu menu;
        menu.showMenu();
        do {
            Stats stats;
            Board board(25, 25, 100, stats);
            Logic logic(board);
            Tools tool(board, stats, logic);
            Controller controller(stats, board, logic, tool, menu.getGameMode());
            SFMLView view(board, tool, menu);
            SFMLController ctrl(stats, board, mgr, logic, tool, controller, menu, view);
            ctrl.play();
        }while (mgr.getGame() == 2);
    }while (mgr.getGame() == 1);
}
