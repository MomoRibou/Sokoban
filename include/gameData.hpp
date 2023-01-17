#include "file.hpp"

#pragma once

class GameData
{
public:
    GameData(int width, int height) : gridWidth(width), gridHeight(height), gameWin(false), nbrCoup(0), grid(height, std::vector<int>(width)), grid_win(grid)
    {
    }
    ~GameData()
    {
    }
    bool movePlayer(Direction dir);
    void fusion();
    bool loadFromFile(std::string fileName);
    int count_box();
    int count_win();
    bool check_win();
    void init();
    void print();
    int get_width()
    {
        return (gridWidth);
    };
    int get_height()
    {
        return (gridHeight);
    };
    int get_gridValue(int row, int col)
    {
        return (grid[row][col]);
    };
    int get_nbrCoup()
    {
        return (nbrCoup);
    };

private:
    int gridWidth;
    int gridHeight;
    bool gameWin;
    int nbrCoup;
    std::vector<std::vector<int>> grid;
    std::vector<std::vector<int>> grid_win;
};
