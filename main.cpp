
#include "MinesweeperBoard.h"
#include "MSSFMLView.h"
#include "SFML/Graphics.hpp"
#include "MSSFMLController.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"
#include <iostream>

int main() {
    srand(time(nullptr));
    sf::RenderWindow window(sf::VideoMode(900, 800), "Grafika w C++/SFML");
    window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(30);

    MinesweeperBoard board(10, 10, EASY);
    MSSFMLView view (board);  // przekazujemy przez referencję planszę jako argument konstruktora


    // symulujemy rozgrywkę
//    board.toggleFlag(0,0);
//    board.revealField(2,2);

    board.debug_display();
    std::cout<<board.getBoardHeight()<<std::endl;
    std::cout<<board.getBoardWidth()<<std::endl;
    MSBoardTextView widok ( board );
    MSTextController ctrl(board, widok);
    MSSFMLView mssfmlViewview (board);
    MSSFMLController ruch (board, view);

    board.debug_display();
    board.display();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
            switch (event.type)
            {
                case  sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseButtonPressed:
                    switch(event.key.code)
                    {
                        case sf::Mouse::Left:
                            ruch.click(event, window);
                            break;

                        case sf::Mouse::Right:
                            ruch.click(event, window);
                            break;
                    }
            }
        window.clear();
        view.draw(window);
        window.display();
    }
    return 0;
}