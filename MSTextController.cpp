#include "MSTextController.h"
#include "MinesweeperBoard.h"
#include <iostream>

MSTextController::MSTextController(MinesweeperBoard & board_var, MSBoardTextView & view_var): msvboard(board_var), msview(view_var) {}

void MSTextController::play() {
    std::cout << std::endl << "GRA" << std::endl;
    while (msvboard.getGameState() == RUNNING) {

        std::cout << std::endl << "1 ODSLON POLE" <<std::endl;
       std::cout << "2 DAJ FALGE" << std::endl;
        int ruch;
        std::  cout << "ruch: ";
        std::cin >> ruch;

        int row, col;
        std:: cout << std::endl;
        std:: cout << "kolumna= ";
        std:: cin >> col;
        std:: cout << "" <<std:: endl;
        std::  cout << "szerokosc = ";
        std:: cin >> row;

        if (ruch == 1) {
            msvboard.revealField(row, col);
        }
        if (ruch == 2) {
            msvboard.toggleFlag(row, col);
        }
        if (ruch != 1 && ruch != 2) {
            std:: cout << "WYBIERZ POPRAWNA OPCJE";
            break;
        }
        msview.display_board();
        std:: cout << std::endl<<std::endl;
    }
}
