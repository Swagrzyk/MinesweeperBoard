#ifndef MINESWEEPERBOARD_MSSFMLVIEW_H
#define MINESWEEPERBOARD_MSSFMLVIEW_H
#include "SFML/Graphics.hpp"
#include "MinesweeperBoard.h"

class MSSFMLView
{
    MinesweeperBoard & board;
    sf::Font font;
    sf::Texture bomba;
    sf::Texture flaga;
public:
    explicit MSSFMLView(MinesweeperBoard & b);

    void draw (sf::RenderWindow & win);
};
#endif //MINESWEEPERBOARD_MSSFMLVIEW_H

