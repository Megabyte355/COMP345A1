/*
 * Position.cpp
 *
 *  Created on: Oct 21, 2013
 *      Author: Gary Chang
 */

#include "Position.h"

Position::Position()
{
    this->x = 0;
    this->y = 0;
}

Position::~Position()
{
}

Position::Position(int x, int y)
{
    this->x = x;
    this->y = y;
}
