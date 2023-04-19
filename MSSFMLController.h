#include <iostream>
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"
#include "MSSFMLView.h"
#include <SFML/Graphics.hpp>


#ifndef MINESWEEPERBOARD_MSSFMLCONTROLLER_H
#define MINESWEEPERBOARD_MSSFMLCONTROLLER_H



class MSSFMLController {

    MinesweeperBoard & board;

public:
    void click(sf::Event& event, sf::RenderWindow &window) ;

    MSSFMLView &view;

    MSSFMLController (MinesweeperBoard &b ,MSSFMLView & v);
};


#endif //MINESWEEPERBOARD_MSSFMLCONTROLLER_H