
#ifndef MINESWEEPERBOARD_MSTEXTCONTROLLER_H
#define MINESWEEPERBOARD_MSTEXTCONTROLLER_H

#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"

class MSTextController {
    MinesweeperBoard & msvboard;
    MSBoardTextView & msview;

public:
    //MSTextController(MinesweeperBoard &Board, MSSFMLView &board, sf::RenderWindow &win);
    MSTextController(MinesweeperBoard & board_var, MSBoardTextView & view_var);
    void play();

};

#endif //MINESWEEPERBOARD_MSTEXTCONTROLLER_H

