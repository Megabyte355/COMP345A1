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
}

PathUnit::PathUnit(int x, int y)
{
    this->x = x;
    this->y = x;
}

PathUnit::~PathUnit()
{
    // TODO Auto-generated destructor stub
}

std::vector<PathUnit> PathUnit::getNeighbors()
{
    std::vector<PathUnit> neighbors;

    PathUnit up(x, y - 1);
    PathUnit down(x, y + 1);
    PathUnit left(x - 1, y);
    PathUnit right(x + 1, y);

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

bool PathUnit::containedIn(std::vector<PathUnit> vp)
{
    for (unsigned int i = 0; i < vp.size(); i++)
    {
        if (*this == vp[i])
        {
            return true;
        }
    }
    return false;
}
