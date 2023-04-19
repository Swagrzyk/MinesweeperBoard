#include <iostream>
#include <ctime>
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"
#include "MSSFMLView.h"
#include <SFML/Graphics.hpp>
#include "MSSFMLController.h"

using namespace std;

MSSFMLController::MSSFMLController (MinesweeperBoard & b, MSSFMLView & v) : board(b), view(v)
{

}


void MSSFMLController::click(sf::Event& event, sf::RenderWindow &window)
{
    int size;
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

    if (event.type == sf::Event::MouseButtonPressed)
    {
        int col = ((event.mouseButton.x /(size)));
        int row = ((event.mouseButton.y /(size)));

        if(event.mouseButton.button == sf::Mouse::Left)
        {
            cout<<"Left"<<event.mouseButton.button<<endl;
            cout<<"X:"<<event.mouseButton.x<<endl;
            cout<<"Y:"<<event.mouseButton.y<<endl;
            board.revealField(row,col);
            return;
        }
        if(event.mouseButton.button == sf::Mouse::Right)
        {
            cout<<"Right"<<event.mouseButton.button<<endl;
            cout<<"X:"<<event.mouseButton.x<<endl;
            cout<<"Y:"<<event.mouseButton.y<<endl;
            board.toggleFlag(row, col);
            return;

        }
    }

}