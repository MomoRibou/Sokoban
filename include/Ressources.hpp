#include "file.hpp"
#include "gameData.hpp"

#pragma once

class Ressources
{
public:
    Ressources()
    {
        gameClock.restart();
    }
    ~Ressources()
    {
    }
    bool loadResources();
    void drawGame(sf::RenderWindow &window, GameData &gameData);
    void chronometre();
    void screenVictory(sf::RenderWindow &window, GameData &gamedata);

private:
    sf::Texture playerTexture;
    sf::Texture wallTexture;
    sf::Texture boxTexture;
    sf::Clock gameClock;
    sf::Text timeText;
    sf::Text mooveText;
    sf::Font font;
};
