#ifndef MINESWEEPERBOARD_MINESWEEPERBOARD_H
#define MINESWEEPERBOARD_MINESWEEPERBOARD_H

enum GameMode  { DEBUG, EASY, NORMAL, HARD };
enum GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS };


struct Field
{
    bool hasMine;
    bool hasFlag;
    bool isRevealed;
};
class MinesweeperBoard
{
    GameMode mode;
    GameState uno;
    Field board[100][100];
    int width;
    int height;
    void clear_board();
public:
    bool checkWin() const;
    MinesweeperBoard();
    bool gameOver();
    void debug_display() const;
    int getBoardWidth() const;
    int getBoardHeight() const;
    int getMineCount() const;
    int countMines( int row,int col) const;
    MinesweeperBoard(int w, int h, GameMode mode);
    void toggleFlag(int row, int col);
    GameState getGameState() const;
    bool invalid(int row,int col)const;
    bool is_revealed(int row, int col)const;
    bool hasFlag(int row, int col) const;
    bool has_mine(int row, int col) const;
    bool isRevealed(int row, int col)const;
    void revealField(int row, int col);
    char getFieldInfo(int row,int col) const;
    bool has_flag(int row, int col) const;
    bool inside_board(int row, int col) const;
    void display()const;

};


#endif //MINESWEEPERBOARD_MINESWEEPERBOARD_H
