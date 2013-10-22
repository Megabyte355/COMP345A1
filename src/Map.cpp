/*
 * Map.cpp
 *
 *  Created on: Oct 21, 2013
 *      Author: Gary
 */

#include "Map.h"

Map::Map()
{
    mapWidth = 10;
    mapHeight = 10;
}

Map::~Map()
{
    // TODO Auto-generated destructor stub
}

Map::Map(int numColumns, int numRows)
{
    mapWidth = numColumns;
    mapHeight = numRows;

    // Initialize all cells as Surface Cells
    matrix.resize(mapWidth);
    for (int i = 0; i < mapWidth; i++)
    {
        matrix[i].resize(mapHeight);
        for (int j = 0; j < mapHeight; j++)
        {
            matrix[i][j] = std::make_shared<Cell>(Cell::CellType::Surface);
        }
    }
}

int Map::getWidth()
{
    return mapWidth;
}

int Map::getHeight()
{
    return mapHeight;
}

std::shared_ptr<Cell> Map::getCell(int x, int y)
{
    return matrix[x][y];
}

std::shared_ptr<Cell> Map::getStartCell()
{
    for (int i = 0; i < mapWidth; i++)
    {
        for (int j = 0; j < mapHeight; j++)
        {
            if (matrix[i][j]->getType() == Cell::CellType::Start)
            {
                return matrix[i][j];
            }
        }
    }
    return nullptr;
}

std::shared_ptr<Cell> Map::getEndCell()
{
    for (int i = 0; i < mapWidth; i++)
    {
        for (int j = 0; j < mapHeight; j++)
        {
            if (matrix[i][j]->getType() == Cell::CellType::End)
            {
                return matrix[i][j];
            }
        }
    }
    return nullptr;
}

void Map::setCell(Cell::CellType cellType, int x, int y)
{
    matrix[x][y].reset();
    matrix[x][y] = std::make_shared<Cell>(cellType);
    matrix[x][y]->setX(x);
    matrix[x][y]->setY(y);
}

void Map::setStartCell(int x, int y)
{
    if (getStartCell() != nullptr)
    {
        getStartCell()->setType(Cell::CellType::Surface);
    }
    matrix[x][y].reset();
    matrix[x][y] = std::make_shared<Cell>(Cell::CellType::Start);
    matrix[x][y]->setX(x);
    matrix[x][y]->setY(y);
}

void Map::setEndCell(int x, int y)
{
    if (getEndCell() != nullptr)
    {
        getEndCell()->setType(Cell::CellType::Surface);
    }
    matrix[x][y].reset();
    matrix[x][y] = std::make_shared<Cell>(Cell::CellType::End);
    matrix[x][y]->setX(x);
    matrix[x][y]->setY(y);
}

bool Map::isValidMap()
{
    std::shared_ptr<Cell> start = getStartCell();
    std::shared_ptr<Cell> end = getEndCell();

    bool hasStart = start != nullptr;
    bool hasEnd = end != nullptr;
    bool hasValidPath = false;
    if (hasStart && hasEnd)
    {
        hasValidPath = isValidPath(*start, *end);
    }

    // has a start
    // has an end
    // has a valid path from these two points
    return hasStart && hasEnd && hasValidPath;
}

bool Map::isValidPath(Cell src, Cell dest)
{
    //return !findPath(src, dest).empty();
    Path path(std::make_shared<std::vector<std::vector<std::shared_ptr<Cell>>>>(matrix), mapWidth, mapHeight);
    return path.validPath(src, dest);
}

bool Map::isValidCell(Cell c)
{
    return isValidCell(c.getX(), c.getY());
}

bool Map::isValidCell(int x, int y)
{
    return x >= 0 && x < mapWidth && y >= 0 && y < mapHeight;
}

void Map::printMap()
{
    std::cout << "  ";
    for (int k = 0; k < mapWidth; k++)
    {
        std::cout << k;
    }
    std::cout << std::endl;
    for (int j = 0; j < mapHeight; j++)
    {
        std::cout << j << " ";
        for (int i = 0; i < mapWidth; i++)
        {
            if (matrix[i][j]->getType() == Cell::CellType::Surface)
            {
                std::cout << "_";
            }
            else if (matrix[i][j]->getType() == Cell::CellType::Wall)
            {
                std::cout << "X";
            }
            else if (matrix[i][j]->getType() == Cell::CellType::Start)
            {
                std::cout << "S";
            }
            else if (matrix[i][j]->getType() == Cell::CellType::End)
            {
                std::cout << "E";
            }
            else
            {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}

void Map::resetMap()
{
    for (int i = 0; i < mapWidth; i++)
    {
        for (int j = 0; j < mapHeight; j++)
        {
            matrix[i][j].reset();
            matrix[i][j] = std::make_shared<Cell>(Cell::CellType::Surface);
        }
    }

}
