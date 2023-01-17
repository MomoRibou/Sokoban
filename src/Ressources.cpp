#include "Ressources.hpp"

bool Ressources::loadResources()
{
    if (!playerTexture.loadFromFile("player.png"))
        return (false);
    if (!wallTexture.loadFromFile("wall.png"))
        return (false);
    if (!boxTexture.loadFromFile("box.png"))
        return (false);
    if (!font.loadFromFile("arial.ttf"))
        return (false);
    return (true);
}

void Ressources::drawGame(sf::RenderWindow &window, GameData &gameData)
{
    sf::Sprite playerSprite;
    sf::Sprite wallSprite;
    sf::Sprite boxSprite;
    playerSprite.setTexture(playerTexture);
    wallSprite.setTexture(wallTexture);
    boxSprite.setTexture(boxTexture);
    for (int row = 0; row < gameData.get_height(); row++)
    {
        for (int col = 0; col < gameData.get_width(); col++)
        {
            int gridValue = gameData.get_gridValue(row, col);
            gameData.fusion();
            sf::Sprite *s;
            switch (gridValue)
            {
            case 0:
                continue;
            case 1:
                s = &wallSprite;
                break;
            case 2:
                s = &boxSprite;
                s->setColor(sf::Color(255, 255, 255, 255));
                break;
            case 3:
                s = &playerSprite;
                break;
            case 4:
                s = &boxSprite;
                s->setColor(sf::Color(255, 255, 255, 64));
                break;
            }
            s->setPosition(col * CELL_SIZE, row * CELL_SIZE);
            window.draw(*s);
        }
    }
    window.draw(timeText);
}

void Ressources::chronometre()
{
    sf::Time elapsedTime = gameClock.getElapsedTime();
    int elapsedMilliseconds = elapsedTime.asMilliseconds();
    int minutes = elapsedMilliseconds / 60000;
    int seconds = (elapsedMilliseconds % 60000) / 1000;
    int milliseconds = elapsedMilliseconds % 1000;
    std::string str_minutes;
    std::string str_seconds;
    std::string str_milliseconds;
    if (minutes < 10)
        str_minutes = "0" + std::to_string(minutes);
    else
        str_minutes = std::to_string(minutes);
    if (seconds < 10)
        str_seconds = "0" + std::to_string(seconds);
    else
        str_seconds = std::to_string(seconds);
    str_milliseconds = std::to_string(milliseconds).substr(0, 2);
    timeText.setString("Temps : " + str_minutes + ":" + str_seconds + ":" + str_milliseconds);
    timeText.setFont(font);
    timeText.setCharacterSize(24);
    timeText.setPosition(5, 0);
    timeText.setFillColor(sf::Color::White);
}

void Ressources::screenVictory(sf::RenderWindow &window, GameData &gamedata)
{
    mooveText.setString("Victoire !\nNiveau Reussi\nCoups utiises : " + std::to_string(gamedata.get_nbrCoup()));
    mooveText.setFont(font);
    mooveText.setCharacterSize(24);
    mooveText.setPosition(5, 0);
    mooveText.setFillColor(sf::Color::White);
    timeText.setPosition(5, 85);
    window.draw(timeText);
    window.draw(mooveText);
}
