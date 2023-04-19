#include "MinesweeperBoard.h"
#include <iostream>
#include <cstdlib>

MinesweeperBoard::MinesweeperBoard(int w, int h,GameMode mode) {
    // konstruktor
    width = w;
    height = h;
    //clear board
    clear_board();

    switch (mode) {
        case DEBUG: {
            for (int row=0; row<height;row++){
                for(int column=0; column<width;column++){
                    if(row == 0)
                    {
                    board[row][width].hasMine =true;
                     }
                    else if (column == 0 && (row % 2 ==0)) {
                        board[row][width].hasMine = true;
                    }
                        else if (column == 1 && (row % 3 ==0))
                    {
                            board[row][width].hasMine = true;
                    }
                }
            }
        }
            break;
        case EASY: {
            int Mines_Easy = (width * height) * 0.1;
            std::cout << Mines_Easy << std::endl;
            for (int bomby = 0; bomby < Mines_Easy; bomby++) {
                int Randomheight = rand() % height;
                int Randomwidth = rand() % width;
                if (board[Randomheight][Randomwidth].hasMine)
                    bomby -= 1;
                board[Randomheight][Randomwidth].hasMine = true;
            }
        }
            break;
        case NORMAL: {
            int Mines_NORMAL = (width * height) * 0.2;
            std::cout << Mines_NORMAL << std::endl;
            for (int bomby = 0; bomby < Mines_NORMAL; bomby++) {
                int Randomheight = rand() % height;
                int Randomwidth = rand() % width;
                if (board[Randomheight][Randomwidth].hasMine)
                    bomby -= 1;
                board[Randomheight][Randomwidth].hasMine = true;
            }
        }
            break;
        case HARD: {
            int Mines_HARD = (width * height) * 0.3;
            std::cout << Mines_HARD << std::endl;
            for (int bomby = 0; bomby < Mines_HARD; bomby++) {
                int Randomheight = rand() % height;
                int Randomwidth = rand() % width;
                if (board[Randomheight][Randomwidth].hasMine)
                    bomby -= 1;
                board[Randomheight][Randomwidth].hasMine = true;
            }
        }
            break;
    }
}
    void MinesweeperBoard::clear_board(){//CZYSZCZENIE TABLICY
        for(int row=0;row<height;row++){
            for(int col=0;col<width;col++){
                board[row][col].hasMine = false;
                board[row][col].hasFlag = false;
                board[row][col].isRevealed = false;
            }
        }
    }
    void MinesweeperBoard::debug_display() const{
        for(int row=0;row<height;row++){
            for(int col=0;col<width;col++){
                std::cout << "[";
                if(board[row][col].hasMine)
                    std::cout << "M";
                else
                    std::cout << ".";
                if(board[row][col].isRevealed)
                    std::cout << "o";
                else
                    std::cout << ".";
                if(board[row][col].hasFlag)
                    std::cout << "f";
                else
                    std::cout << ".";
                std::cout << "]";
            };
            std::cout<<std::endl;
        };
    }
    int MinesweeperBoard::getBoardWidth() const{
        return width;
    }
    int MinesweeperBoard::getBoardHeight() const{
        return height;
    }
    int MinesweeperBoard::getMineCount() const {
        int licz=0;
        for(int row=0;row<width;row++){
            for(int col =0;col<height;col++){
                if(board[row][col].hasMine== true) {
                    licz++;
                }
            }
        }
        return licz;
    }
    bool MinesweeperBoard::hasFlag(int row, int col) const{
        if(row>height-1 || col>width-1){
            return false;
        }
        if(board[row][col].hasFlag){
            return true;
        }
        if(!board[row][col].hasFlag){
            return false;
        }
        if(!invalid(row,col)){
            return false;
        }
        return false;
    }

        bool MinesweeperBoard::inside_board(int row, int col) const {
            if(row>=height||col>=width||row<0||col<0)
                return false;
            return true;

        }
bool MinesweeperBoard::gameOver()
{
    debug_display();
    // Ustawiamy wszystkie pola jako odkryte, aby nie można było już wykonywać ruchów
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            board[row][col].isRevealed = true;
        }
    }

    // Sprawdzenie, czy gra została wygrana
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            if (board[row][col].isRevealed || board[row][col].hasFlag) {
                if (!board[row][col].hasMine) {
                    continue;
                }
            }
            else if (board[row][col].hasMine) {
                return true;
            }
        }
    }
    return false;
}
bool MinesweeperBoard::checkWin() const {
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            if (!board[row][col].hasMine && !board[row][col].isRevealed) {
                // znaleziono pole, które nie jest miną i nie jest odkryte
                return false;
            }
        }
    }
    // nie znaleziono żadnego pola, które nie jest miną i nie jest odkryte
    return true;
}

void MinesweeperBoard::revealField(int row, int col)
{
    if (board[row][col].isRevealed == true) //pole już zostało odkryte
        return;

    board[row][col].isRevealed = true; //odkrywamy pole

    if (board[row][col].hasMine == true) //trafienie w minę
    {
        std::cout << "Boom! You stepped on a mine." << std::endl;
        debug_display();
        gameOver() == true; //ustawiamy zmienną gameOver na true
        return;
    }

    if (countMines(row, col) == 0) //pole nie ma min w sąsiedztwie
    {
        //odkrywamy pola sąsiednie
        for (int r = row - 1; r <= row + 1; r++)
        {
            for (int c = col - 1; c <= col + 1; c++)
            {
                if (inside_board(r, c))
                    revealField(r, c);
            }
        }
    }
    if (checkWin()) {
        std::cout << "Congratulations! You won the game!" << std::endl;
        gameOver() == true;
        debug_display();
        // można też dodać kod, który zapisze wynik do pliku, np. z wynikami wszystkich graczy
    }
}

bool MinesweeperBoard::is_revealed(int row, int col) const {
    if (inside_board(row, col) && board[row][col].isRevealed) { return true; }
    else { return false; }
}
bool MinesweeperBoard::has_flag(int row, int col) const {
    if (inside_board(row, col) && board[row][col].hasFlag) { return true; }
    else { return false; }
}

bool MinesweeperBoard::has_mine(int row, int col) const {
    if(inside_board(row, col) && board[row][col].hasMine) { return true; }
    else { return false; }
}
    bool MinesweeperBoard::invalid(int row,int col)const{
        if(row>width or col>height or col <=0 or row<=0) {
            return false;
        }
        return true;
    }
    void MinesweeperBoard:: toggleFlag(int row, int col){
    if( is_revealed(row, col) || !inside_board(row, col) ||
    getGameState() == FINISHED_WIN || getGameState() == FINISHED_LOSS ||
    has_flag(row, col) ) {
    return;
        } else if(!is_revealed(row, col)) {
    board[row][col].hasFlag = true;
        }
    }
char MinesweeperBoard::getFieldInfo(int row, int col)const {
        if(row>height or col>width or row <0 or col<0){
        return '#';
        }
        if (isRevealed(row, col) == false and hasFlag(row, col) == true) {
            return 'F';
        }
        if (isRevealed(row, col) == false and hasFlag(row, col) == false) {
            return '_';
        }
        if (isRevealed(row, col) == true and has_mine(row, col) == true) {
            return 'x';
        }
        if (isRevealed(row, col) == true and countMines(row, col) == 0) {
            return ' ';
        }
        if (isRevealed(row, col) and countMines(row, col) != 0) {
            char mines = (countMines(row, col))+'0';
            return mines;
        }
        return '$';
    }

    int MinesweeperBoard::countMines(int row, int col) const{
        int near =0;
        if ( !inside_board(row, col) ) { // || !is_revealed(row, col)
            return -1;
        }
        else {

            if(inside_board(row - 1, col - 1) && board[row - 1][col - 1].hasMine) {
                near++;
            }
            if(inside_board(row - 1, col) && board[row - 1][col].hasMine) {
                near++;
            }
            if(inside_board(row - 1, col + 1) && board[row - 1][col + 1].hasMine ) {
                near++;
            }
            if(inside_board(row, col - 1) && board[row][col - 1].hasMine) {
                near++;
            }
            if(inside_board(row, col + 1) && board[row][col + 1].hasMine ) {
                near++;
            }
            if(inside_board(row + 1, col - 1) && board[row + 1][col - 1].hasMine) {
                near++;
            }
            if(inside_board(row + 1, col) && board[row + 1][col].hasMine) {
                near++;
            }
            if(inside_board(row + 1, col + 1) && board[row + 1][col + 1].hasMine) {
                near++;
            }
            return near;
        }
    }

    bool MinesweeperBoard::isRevealed(int row, int col) const {
        if (board[row][col].isRevealed == true) {
            return FINISHED_WIN;
        }
        return false;
    }
void MinesweeperBoard::display() const {



    for(int row = 0;row < getBoardHeight();row++)
    {
        for(int col = 0;col < getBoardWidth(); col++)
        {
            std::cout << "[" << getFieldInfo(row, col) << "]";
        }
        std::cout << std::endl;
    } std::cout <<std::endl;
}
    GameState MinesweeperBoard::getGameState() const{
        int Pol = 0;
        int Flag = 0;
        for(int col = 0; col > getBoardHeight(); col++ ){
            for(int row = 0; row > getBoardWidth(); row++ ){
                if (has_mine(row, col) == true and isRevealed(row, col) == true){
                    return FINISHED_LOSS;
                }
                if (has_mine(row, col) == false and isRevealed(row, col) == true){
                    Pol++;
                }
                if (has_mine(row, col) == true and hasFlag(row, col) == true){
                    Flag++;
                }
            }
        }
        if(Flag == getMineCount() and Pol == getBoardWidth() * getBoardHeight() - getMineCount())
            return FINISHED_WIN;
        else
            return RUNNING;
    }
