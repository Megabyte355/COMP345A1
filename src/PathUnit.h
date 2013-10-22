/*
 * PathUnit.h
 *
 *  Created on: Oct 21, 2013
 *      Author: Gary
 */

#ifndef PATHUNIT_H_
#define PATHUNIT_H_

#include <vector>
#include <memory>

class PathUnit
{
    public:
        int x;
        int y;
        int depth;

        PathUnit();
        PathUnit(int,int);
        ~PathUnit();

        bool operator==(PathUnit&);
        bool containedIn(std::vector<PathUnit>);
        std::vector<PathUnit> getNeighbors();
};

#endif /* PATHUNIT_H_ */
