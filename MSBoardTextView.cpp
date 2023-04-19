#include "MSBoardTextView.h"
#include "MinesweeperBoard.h"
#include <iostream>
using namespace std;


MSBoardTextView::MSBoardTextView (MinesweeperBoard &game) : msboard(game){}

void MSBoardTextView::display_board() const
{
    int height;
    height = msboard.getBoardHeight();
    int width;
    width = msboard.getBoardWidth();

    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            cout << "[" << msboard.getFieldInfo(row,col)<<"]";
        }
        cout << endl;
    }
}

