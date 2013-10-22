/*
 * Map.cpp
 *
 *  Created on: Oct 21, 2013
 *      Author: Gary
 */

#include "Map.h"

Map::Map() :
        Map(10, 10)
{
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
    if (getStartCell() == nullptr)
    {
        matrix[x][y].reset();
        matrix[x][y] = std::make_shared<Cell>(Cell::CellType::Start);
        matrix[x][y]->setX(x);
        matrix[x][y]->setY(y);
    }

}

void Map::setEndCell(int x, int y)
{
    if (getEndCell() == nullptr)
    {
        matrix[x][y].reset();
        matrix[x][y] = std::make_shared<Cell>(Cell::CellType::End);
        matrix[x][y]->setX(x);
        matrix[x][y]->setY(y);
    }
}

bool Map::isValidMap()
{
    std::shared_ptr<Cell> start = getStartCell();
    std::shared_ptr<Cell> end = getStartCell();

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
    return !findPath(src, dest).empty();
}

bool Map::isValidCell(Cell c)
{
    return isValidCell(c.getX(), c.getY());
}

bool Map::isValidCell(int x, int y)
{
    return x >= 0 && x < mapWidth && y >= 0 && y < mapHeight;
}

std::vector<PathUnit> Map::findPath(Cell src, Cell dest)
{

    unsigned int depth = 0;
    int foundAtDepth = 0;
    bool destinationFound = false;

    PathUnit start(src.getX(), src.getY(), depth);
    std::vector<PathUnit> path;
    path.push_back(start);

    // Check if source and destination are valid cells
    if (!isValidCell(src) || !isValidCell(dest))
    {
        path.clear();
        return path;
    }

    // The real algorithm begins here
    while (!destinationFound)
    {
        // If we still didn't find the destination, it means it's unreachable
        if (depth > path.size())
        {
            path.clear();
            return path;
        }

        std::vector<PathUnit> neighbors(path[depth].getNeighbors());
        for (PathUnit n : neighbors)
        {

            // Check if it's out of boundary
            if (!isValidCell(n.x, n.y))
            {
                continue;
            }

            // Check if it is already in path
            bool alreadyInPath = false;
            for (PathUnit p : path)
            {
                if (n == p)
                {
                    alreadyInPath = true;
                    break;
                }
            }
            if (alreadyInPath)
            {
                continue;
            }

            // Check Type
            Cell::CellType type = matrix[n.x][n.y]->getType();
            if (type == Cell::CellType::Empty || type == Cell::CellType::Wall)
            {
                continue;
            }

            // Check if it's the destination
            if (n.x == dest.getX() && n.y == dest.getY())
            {
                destinationFound = true;
                foundAtDepth = depth;
            }

            path.push_back(n);
        }

        depth++;
    }

    // Constructing the reversedPath
    if (destinationFound)
    {
        int targetDepth = foundAtDepth - 1;
        bool pathComplete = false;
        std::vector<PathUnit> candidates;
        std::vector<PathUnit> reversedPath;

        reversedPath.push_back(path.back());

        while (!pathComplete)
        {
            // Find candidates from path (based on targetDepth)
            for (PathUnit p : path)
            {
                if (p.depth == targetDepth)
                {
                    candidates.push_back(p);
                }
            }

            // Compare neighbors of reversedPath.back()
            std::vector<PathUnit> currentNeighbors(reversedPath.back().getNeighbors());
            bool neighborMatch = false;
            for (PathUnit c : candidates)
            {
                for (PathUnit n : currentNeighbors)
                {
                    if (c == n && c.depth == targetDepth)
                    {
                        // A PathUnit belonging to the correct path is found
                        reversedPath.push_back(c);
                    }
                }
            }

            for (unsigned int c = 0; c < candidates.size() && !neighborMatch; c++)
            {
                for (unsigned int n = 0; n < currentNeighbors.size() && !neighborMatch; n++)
                {
                    if (candidates[c] == currentNeighbors[n] && candidates[c].depth == targetDepth)
                    {
                        // A PathUnit belonging to the correct path is found
                        reversedPath.push_back(candidates[c]);
                        neighborMatch = true;

                        if ((getStartCell()->getX() == reversedPath.back().x)
                                && (getStartCell()->getY() == reversedPath.back().y))
                        {
                            pathComplete = true;
                        }

                    }
                }
            }
            targetDepth--;
            candidates.clear();
        }

        // Reverse the reveredPath
        std::vector<PathUnit> correctPath;
        for (unsigned int i = reversedPath.size() - 1; i >= 0; i--)
        {
            correctPath.push_back(reversedPath[i]);
        }

//        PathUnit destination(path.back());
//        filteredPath.push_back(path.back());
//
//        bool done = false;
//
//        while (!done)
//        {
//            for (PathUnit p : path)
//            {
//                if (p.depth == targetDepth)
//                {
//                    candidates.push_back(p);
//                }
//            }
//
//            std::vector<PathUnit> neighborPreview(destination.getNeighbors());
//            for(PathUnit c : candidates)
//            {
//                for (PathUnit n : neighborPreview)
//                {
//                    if (c == n && c.depth == targetDepth)
//                    {
//                        filteredPath.push_back(c);
//                        break;
//                    }
//                }
//            }
//        }
    }
    path.clear();
    return path;

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
