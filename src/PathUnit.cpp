/*
 * PathUnit.cpp
 *
 *  Created on: Oct 21, 2013
 *      Author: Gary
 */

#include "PathUnit.h"

PathUnit::PathUnit()
{
    x = 0;
    y = 0;
    depth = 0;
}

PathUnit::PathUnit(int x, int y, int depth)
{
    this->x = x;
    this->y = x;
    this->depth = depth;
}

PathUnit::~PathUnit()
{
    // TODO Auto-generated destructor stub
}

std::vector<PathUnit> PathUnit::getNeighbors()
{
    std::vector<PathUnit> neighbors;

    PathUnit up(x, y - 1, depth + 1);
    PathUnit down(x, y + 1, depth + 1);
    PathUnit left(x - 1, y, depth + 1);
    PathUnit right(x + 1, y, depth + 1);

    neighbors.push_back(up);
    neighbors.push_back(down);
    neighbors.push_back(left);
    neighbors.push_back(right);
    return neighbors;
}

bool PathUnit::operator==(PathUnit &p)
{
    return this->x == p.x && this->y == p.y;
}

