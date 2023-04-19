#ifndef MINESWEEPERBOARD_MSBOARDTEXTVIEW_H
#define MINESWEEPERBOARD_MSBOARDTEXTVIEW_H
#include "MinesweeperBoard.h"

class MSBoardTextView {
    int width;
    int height;
    MinesweeperBoard & msboard;
public:
    explicit MSBoardTextView(MinesweeperBoard & game);
    void display_board() const;
};


#endif //MINESWEEPERBOARD_MSBOARDTEXTVIEW_H
