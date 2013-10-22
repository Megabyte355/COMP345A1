/*
 * Cell.h
 *
 *  Created on: Oct 21, 2013
 *      Author: Gary Chang
 */

#ifndef CELL_H_
#define CELL_H_

#include "CellOccupant.h"
#include <memory>

class Cell
{
    public:
        enum CellType
        {
            Wall, Surface, Empty, Start, End
        };

        Cell();
        Cell(CellType);
        ~Cell();

        CellType getType();
        void setType(CellType);
        void setX(int);
        void setY(int);
        int getX();
        int getY();
        void clearOccupant();
        void setOccupant(std::shared_ptr<CellOccupant>);
        std::shared_ptr<CellOccupant> getOccupant();

    private:
        CellType type;
        int x;
        int y;
        std::shared_ptr<CellOccupant> occupant;
};

#endif /* CELL_H_ */
