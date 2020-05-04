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
#include <fstream>

using namespace std;

int main() {
    Menu menu;
    menu.showMenu();
    Stats stats;
    Board board(25, 25, 100, stats);
    Logic logic(board);
    Tools tool(board, stats, logic);
    cout << "MODE: " << menu.getGameMode() << endl;
    Controller controller(stats,board,logic,tool,menu.getGameMode());
//    ////// TextView viewText(board, tool);
//    ////// viewText.view();
    cout << "fence: " << menu.getFenceSkin() << endl;
    cout << "fruit: " << menu.getFruitSkin() << endl;
    cout << "obstacle: " << menu.getObstacleSkin() << endl;
    SFMLView view(board, tool, menu);
    cout << "mode: " << controller.getGameMode() << endl;
    SFMLController ctrl(stats, board, logic, tool, controller, menu, view);
    ctrl.play();
}
