#include <iostream>
#include "Board.h"
#include "Tools.h"
#include "Stats.h"
#include "Logic.h"
#include "Controller.h"
#include "TextView.h"
#include "Menu.h"
#include "Manager.h"
#include "PostGame.h"
#include "Highscore.h"
#include "SFMLView.h"
#include "SFMLController.h"

using namespace std;

int main() {
    Manager mgr;
    do {
        ///// MENU
        Highscore scores;
        Menu menu(scores);
        menu.showMenu();
        do {
            ///// GAME
            Stats stats;
            Board board(25, 25, 50, stats);
            Logic logic(board);
            Tools tool(board, stats, logic);
            Controller controller(stats, board, logic, tool, menu.getGameMode());
            SFMLView view(board, tool, menu);
            SFMLController ctrl(stats, board, mgr, logic, tool, controller, menu, view, scores);
            ctrl.play();
        }while (mgr.getGame() == 2);
    }while (mgr.getGame() == 1);
}
