/*
 * CellOccupant.h
 *
 *  Created on: Oct 21, 2013
 *      Author: Gary Chang
 */

#ifndef CELLOCCUPANT_H_
#define CELLOCCUPANT_H_

class CellOccupant
{
    public:
        enum OccupantType
        {
            Item, Player, Monster
        };
        CellOccupant();
        ~CellOccupant();

        OccupantType type;
};

#endif /* CELLOCCUPANT_H_ */
