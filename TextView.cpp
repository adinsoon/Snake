#include "TextView.h"


TextView::TextView(Board &b1, Tools &t1) : board(b1), tools(t1) {

}

void TextView::view() {
    for(int row=0;row<board.getBoardHeight();row++){
        for(int col=0;col<board.getBoardWidth();col++){
            std::cout << tools.getFieldInfo(row,col);
        }
        std::cout << std::endl;
    }
}
