#include "MSSFMLView.h"

MSSFMLView::MSSFMLView(MinesweeperBoard & b) : board(b) {}

void MSSFMLView::draw(sf::RenderWindow & win) {
    // tu robimy rysowanie planszy na podstawie zawartości "board"
    int size=50;
    if(board.getBoardWidth()<=10 or board.getBoardHeight()<=10)
    {
        size =80;
    }
    if(board.getBoardWidth()>10 and board.getBoardWidth()<=40 or board.getBoardWidth()>10 and board.getBoardHeight()<=40)
    {
        size =20;
    }
    if(board.getBoardWidth()>40 or board.getBoardHeight()>40)
    {
        size =8;
    }

    sf::RectangleShape rectangle;
    rectangle.setSize ( sf::Vector2f(size, size) );
    rectangle.setFillColor ( sf::Color{169,169,169} );
    rectangle.setOutlineThickness(1 );
    rectangle.setOutlineColor(sf::Color(0,0,0));

    for (int row = 0; row < board.getBoardHeight(); row++) {
        for (int col = 0; col < board.getBoardWidth(); col++) {
            rectangle.setPosition(((size * col)),( (size * row)));
            win.draw(rectangle);
        }
    }

    if(!font.loadFromFile("../GRAFIKA/arial.ttf") ) {
        return;
    }

    if ( !bomba.loadFromFile("../GRAFIKA/bomb.png") ) {
        return;
    }

    if ( !flaga.loadFromFile("../GRAFIKA/flag.png") ) {
        return;
    }

    for (int row = 0; row < board.getBoardHeight(); row++) {
        for (int col = 0; col < board.getBoardWidth(); col++) {
            if( board.isRevealed(row, col) ) {
                if ( board.has_mine(row, col) ) {
                    rectangle.setFillColor ( sf::Color::Red );
                    rectangle.setPosition(((size * col)),( (size * row)) );
                    win.draw(rectangle);

                    sf::Sprite bomb{bomba};
                    bomb.setPosition(((size * col)), ((size * row)) );
                    bomb.setScale(size*0.0013,size*0.0013);
                    win.draw(bomb);
                } else
                if ( board.countMines(row, col) > 0) {
                    rectangle.setFillColor ( sf::Color::Green );
                    rectangle.setPosition(((size * col)),((size * row)) );
                    win.draw(rectangle);

                    sf::Text number(std::to_string(board.countMines(row, col)), font, 50);
                    number.setPosition(((size * col)), ((size * row)) );

                    number.setFillColor(sf::Color::Black);
                    win.draw(number);
                } else {
                    rectangle.setFillColor ( sf::Color{ 10, 100, 100, 255 } );
                    rectangle.setPosition((size * col), (size * row) );
                    win.draw(rectangle);
                }
            }
            if ( board.hasFlag(row, col) ) {
                sf::Sprite flag{flaga};
                flag.setPosition(( (size * col)), ((size * row)) );
                flag.setScale(size*0.00082,size*0.00082);
                win.draw(flag);
            }

        }
    }

}