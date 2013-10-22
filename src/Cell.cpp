/*
 * Cell.cpp
 *
 *  Created on: Oct 21, 2013
 *      Author: Gary Chang
 */

#include "Cell.h"

Cell::Cell()
{
    this->type = CellType::Empty;
    this->x = 0;
    this->y = 0;
}

Cell::Cell(CellType cellType)
{
    this->type = cellType;
    this->x = 0;
    this->y = 0;
}

Cell::~Cell()
{
}

Cell::CellType Cell::getType()
{
    return type;
}

void Cell::setType(CellType type)
{
    this->type = type;
}

void Cell::setX(int x)
{
    this->x = x;
}

void Cell::setY(int y)
{
    this->y = y;
}

int Cell::getX()
{
    return x;
}

int Cell::getY()
{
    return y;
}

void Cell::clearOccupant()
{
    occupant.reset();
}

void Cell::setOccupant(std::shared_ptr<CellOccupant> occupant)
{
    this->occupant = occupant;
}

std::shared_ptr<CellOccupant> Cell::getOccupant()
{
    return occupant;
}
