/*
 * PathUnit.cpp
 *
 *  Created on: Oct 21, 2013
 *      Author: Gary Chang
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
    this->y = y;
    this->depth = depth;
}

PathUnit::~PathUnit()
{
}

std::vector<PathUnit> PathUnit::getNeighbors()
{
    std::vector<PathUnit> neighbors;

    PathUnit up(this->x, this->y - 1, this->depth + 1);
    PathUnit down(this->x, this->y + 1, this->depth + 1);
    PathUnit left(this->x - 1, this->y, this->depth + 1);
    PathUnit right(this->x + 1, this->y, this->depth + 1);

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

bool PathUnit::isNeighbor(PathUnit p)
{
    if ( p.x == this->x )
    {
        return (p.y == this->y - 1) || (p.y == this->y + 1);
    }
    else if (p.y == this->y)
    {
        return (p.x == this->x - 1) || (p.x == this->x + 1);
    }
    else
    {
        return false; 
    }
}

