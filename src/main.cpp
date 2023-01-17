#include "Ressources.hpp"
#include "file.hpp"
#include "gameData.hpp"

int main()
{
    Ressources res;
    std::string file = "levels/level000.xsb";
    if (!res.loadResources())
    {
        std::cout << "Error loading resources" << std::endl;
        return (-1);
    }
    int width = getWidthSize(file);
    int height = getHeightSize(file);
    GameData gameData(width, height);
    gameData.loadFromFile(file);
    gameData.init();
    sf::RenderWindow window(sf::VideoMode(gameData.get_width() * CELL_SIZE, gameData.get_height() * CELL_SIZE), "Sokoban");
    while (window.isOpen())
    {
        if (gameData.check_win() == false)
            res.chronometre();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed)
            {
                if (gameData.check_win() == false)
                {
                    if (event.key.code == sf::Keyboard::Up)
                    {
                        // std::cout << "UP" << std::endl;
                        gameData.movePlayer(Direction::UP);
                    }
                    else if (event.key.code == sf::Keyboard::Down)
                    {
                        // std::cout << "Down" << std::endl;
                        gameData.movePlayer(Direction::DOWN);
                    }
                    else if (event.key.code == sf::Keyboard::Right)
                    {
                        // std::cout << "Right" << std::endl;
                        gameData.movePlayer(Direction::RIGHT);
                    }
                    else if (event.key.code == sf::Keyboard::Left)
                    {
                        // std::cout << "Left" << std::endl;
                        gameData.movePlayer(Direction::LEFT);
                    }
                }
                if (event.key.code == sf::Keyboard::Escape)
                {
                    window.close();
                }
            }
        }
        if (gameData.check_win() == false)
        {
            window.clear(sf::Color{0x55514eFF});
            res.drawGame(window, gameData);
        }
        else
        {
            window.clear();
            res.screenVictory(window, gameData);
        }
        window.display();
    }
    return (0);
}
