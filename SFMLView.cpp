#include "SFMLView.h"

SFMLView::SFMLView(Board &b1, Tools &t1) : board(b1), tools(t1){
    wall.loadFromFile("..\\icons\\orange_wall.png");
    obstacle.loadFromFile("..\\icons\\obstacle.png");
    blanko.loadFromFile("..\\icons\\blanko.png");
    torso.loadFromFile("..\\icons\\torso.png");
    fruit.loadFromFile("..\\icons\\fruit.png");
    headUP.loadFromFile("..\\icons\\headUP.png");
    headLEFT.loadFromFile("..\\icons\\headLEFT.png");
    headDOWN.loadFromFile("..\\icons\\headDOWN.png");
    headRIGHT.loadFromFile("..\\icons\\headRIGHT.png");
}

void SFMLView::drawBoard(sf::RenderWindow &win1) {
    for(int row=0;row<board.getBoardHeight();row++){
        for(int col=0;col<board.getBoardWidth();col++){
            pieces.setScale(0.3,0.3);
            pieces.setPosition(0+cell*col,0+cell*row);
            if(tools.getFieldInfo(row,col) == '#'){
                pieces.setTexture(wall);
            }
            else if(tools.getFieldInfo(row,col) == '%'){
                pieces.setTexture(fruit);
            }
            else if(tools.getFieldInfo(row,col) == 'X'){
                pieces.setTexture(obstacle);
            }
            else if(tools.getFieldInfo(row,col) == '*'){
                pieces.setTexture(torso);
            }
            else if(tools.getFieldInfo(row,col) == ' ')
                pieces.setTexture(blanko);
            else if(tools.getFieldInfo(row,col) == '^'){
                pieces.setTexture(headUP);
            }
            else if(tools.getFieldInfo(row,col) == '>'){
                pieces.setTexture(headRIGHT);
            }
            else if(tools.getFieldInfo(row,col) == 'v'){
                pieces.setTexture(headDOWN);
            }
            else if(tools.getFieldInfo(row,col) == '<'){
                pieces.setTexture(headLEFT);
            }
            win1.draw(pieces);
        }
    }
}