/*
 * Cell.h
 *
 *  Created on: Oct 21, 2013
 *      Author: Gary
 */

#ifndef CELL_H_
#define CELL_H_

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

    private:
        CellType type;
        int x;
        int y;
        bool occupied;
};

#endif /* CELL_H_ */
