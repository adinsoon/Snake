#include <iostream>
#include "Board.h"
#include "Tools.h"
#include "Stats.h"
#include "GameLogic.h"
#include "Controller.h"
#include "TextView.h"
#include "SFMLView.h"
#include "SFMLController.h"
#include <fstream>

using namespace std;

int main() {
    Stats stats;
    Board board(30, 30, 100, stats);
    GameLogic logic(board);
    Tools tool(board, stats, logic);
    Controller controller(stats,board,logic,tool,BASIC);
    // controller.play();
    TextView viewText(board, tool);
    viewText.view();
    SFMLView view(board, tool);
    SFMLController ctrl(stats, board, tool, controller, view);
    ctrl.play();
}
