#include "file.hpp"

int getWidthSize(std::string fileName)
{
    std::string line;
    unsigned int width = 0;
    std::ifstream mFile(fileName);
    if (mFile.is_open())
    {
        while (getline(mFile, line))
        {
            if (line.length() > width)
                width = line.length();
        }
        mFile.close();
        return (width - 1);
    }
    return (0);
}

int getHeightSize(std::string fileName)
{
    std::string line;
    int count = 0;
    std::ifstream mFile(fileName);
    if (mFile.is_open())
    {
        while (mFile.peek() != EOF)
        {
            getline(mFile, line);
            count++;
        }
        mFile.close();
        return (count);
    }
    return (0);
}