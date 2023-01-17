#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

#pragma once

enum class Direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

const int CELL_SIZE = 32;

int getWidthSize(std::string fileName);
int getHeightSize(std::string fileName);
