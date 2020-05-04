#include "SFMLView.h"

SFMLView::SFMLView(Board &b1, Tools &t1, Menu &m1) : board(b1), tools(t1), menu(m1){
    fen = menu.getFenceSkin();
    fru = menu.getFruitSkin();
    obs = menu.getObstacleSkin();
    upperbar.loadFromFile("..\\icons\\upperbar.png");
    blanko.loadFromFile("..\\icons\\blanko.png");
    torso.loadFromFile("..\\icons\\snake\\torso.png");
    headUP.loadFromFile("..\\icons\\snake\\headUP.png");
    headLEFT.loadFromFile("..\\icons\\snake\\headLEFT.png");
    headDOWN.loadFromFile("..\\icons\\snake\\headDOWN.png");
    headRIGHT.loadFromFile("..\\icons\\snake\\headRIGHT.png");
    /////////////////////////////////////////////////////////////
    if(fen == "red wall")   wall.loadFromFile("..\\icons\\fence\\red_wall.png");
    else if(fen == "orange wall") wall.loadFromFile("..\\icons\\fence\\orange_wall.png");
    else if(fen == "yellow wall") wall.loadFromFile("..\\icons\\fence\\yellow_wall.png");
    else if(fen == "green wall") wall.loadFromFile("..\\icons\\fence\\green_wall.png");
    else if(fen == "mint wall") wall.loadFromFile("..\\icons\\fence\\mint_wall.png");
    else if(fen == "blue wall") wall.loadFromFile("..\\icons\\fence\\blue_wall.png");
    else if(fen == "dark wall") wall.loadFromFile("..\\icons\\fence\\dark_wall.png");
    else if(fen == "pink wall") wall.loadFromFile("..\\icons\\fence\\pink_wall.png");
    /////////////////////////////////////////////////////////////
    if(fru == "apple") fruit.loadFromFile("..\\icons\\fruit\\apple.png");
    else if(fru == "coin") fruit.loadFromFile("..\\icons\\fruit\\coin.png");
    else if(fru == "wing") fruit.loadFromFile("..\\icons\\fruit\\wing.png");
    /////////////////////////////////////////////////////////////
    if(obs == "bush") obstacle.loadFromFile("..\\icons\\obstacle\\bush.png");
    else if(obs == "haystack") obstacle.loadFromFile("..\\icons\\obstacle\\siano.png");
    else if(obs == "lake") obstacle.loadFromFile("..\\icons\\obstacle\\lake.png");
}

void SFMLView::drawBoard(sf::RenderWindow &win1) {
    bar.setTexture(upperbar);
    win1.draw(bar);
    for(int row=0;row<board.getBoardHeight();row++){
        for(int col=0;col<board.getBoardWidth();col++){
            pieces.setScale(0.3,0.3);
            pieces.setPosition(0+cell*col,70+cell*row);
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
