#include "gameData.hpp"

bool GameData::movePlayer(Direction dir)
{
    int playerRow, playerCol;
    // Trouve le joueur sur la grille
    for (int row = 0; row < gridHeight; row++)
    {
        for (int col = 0; col < gridWidth; col++)
        {
            if (grid[row][col] == 3)
            {
                playerRow = row;
                playerCol = col;
                break;
            }
        }
    }

    int newRow = playerRow;
    int newCol = playerCol;
    if (dir == Direction::UP)
        newRow--;
    else if (dir == Direction::DOWN)
        newRow++;
    else if (dir == Direction::LEFT)
        newCol--;
    else if (dir == Direction::RIGHT)
        newCol++;

    if (newRow < 0 || newRow >= gridHeight || newCol < 0 || newCol >= gridWidth)
        return (false); // Le joueur est en dehors de la grille
    int nextCell = grid[newRow][newCol];
    if (nextCell == 1)
        return (false); // C'est un mur
    if (nextCell == 2)
    {
        // C'est une box
        int nextnextRow = newRow + (newRow - playerRow);
        int nextnextCol = newCol + (newCol - playerCol);
        if (nextnextRow < 0 || nextnextRow >= gridHeight || nextnextCol < 0 || nextnextCol >= gridWidth)
            return (false); // Le joueur pousse la box en dehors de la grille
        int nextnextCell = grid[nextnextRow][nextnextCol];
        if (nextnextCell == 2 || nextnextCell == 1)
            return (false); // Le joueur ne peut pas pousser la box car la case n'est pas vide
        else
        {
            grid[nextnextRow][nextnextCol] = 2; // Le joueur pousse la box
        }
    }
    nbrCoup++;
    // Bouge le joueur
    grid[playerRow][playerCol] = 0;
    grid[newRow][newCol] = 3;
    return (true);
}

void GameData::fusion()
{
    for (unsigned int i = 0; i < grid.size(); i++)
    {
        for (unsigned int j = 0; j < grid[i].size(); j++)
        {
            if (grid_win[i][j] == 4)
            {
                if (grid[i][j] != 2 && grid[i][j] != 3)
                {
                    grid[i][j] = 4;
                }
            }
        }
    }
}

int GameData::count_box()
{
    int count = 0;
    for (unsigned int i = 0; i < grid.size(); i++)
    {
        for (unsigned int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == 2)
            {
                count++;
            }
        }
    }
    return (count);
}

int GameData::count_win()
{
    int count = 0;
    for (unsigned int i = 0; i < grid.size(); i++)
    {
        for (unsigned int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == 2 && grid_win[i][j] == 4)
            {
                count++;
            }
        }
    }
    return (count);
}

bool GameData::check_win()
{
    if (count_win() == count_box())
    {
        gameWin = true;
    }
    return (gameWin);
}

bool GameData::loadFromFile(std::string fileName)
{
    gridWidth = getWidthSize(fileName);
    gridHeight = getHeightSize(fileName);

    for (int row = 0; row < gridHeight; row++)
    {
        for (int col = 0; col < gridWidth; col++)
        {
            grid[row][col] = 0;
        }
    }

    std::ifstream file(fileName);
    if (!file.is_open())
        return false;

    std::string line;
    for (int row = 0; row < gridHeight; row++)
    {
        std::getline(file, line);
        std::string newString;

        int nbSpaces = gridWidth - line.size();
        for (int i = 0; i < nbSpaces; i++)
            newString += " ";
        line += newString;
        for (int col = 0; col < gridWidth; col++)
        {
            char c = line[col];
            switch (c)
            {
            case '#':
                grid[row][col] = 1;
                break;
            case ' ':
                grid[row][col] = 0;
                break;
            case '$':
                grid[row][col] = 2;
                break;
            case '@':
                grid[row][col] = 3;
                break;
            case '.':
                grid[row][col] = 4;
                break;
            default:
                grid[row][col] = 0;
            }
        }
    }
    file.close();
    return true;
}

void GameData::init()
{
    for (unsigned int i = 0; i < grid.size(); i++)
    {
        for (unsigned int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == 4)
                grid_win[i][j] = 4;
        }
    }
}

void GameData::print()
{
    for (unsigned int i = 0; i < grid.size(); i++)
    {
        for (unsigned int j = 0; j < grid[i].size(); j++)
        {
            std::cout << grid[i][j];
        }
        std::cout << std::endl;
    }
}
