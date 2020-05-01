#ifndef SNAKEOLD_TEXTVIEW_H
#define SNAKEOLD_TEXTVIEW_H
#include "Board.h"
#include "Tools.h"


class TextView {
    Board &board;
    Tools &tools;
public:
    TextView(Board &b1, Tools &t1);
    void view();
};


#endif //SNAKEOLD_TEXTVIEW_H
