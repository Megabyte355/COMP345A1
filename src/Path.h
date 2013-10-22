/*
 * PathFinder.h
 *
 *  Created on: Oct 21, 2013
 *      Author: Gary Chang
 */

#ifndef PATHFINDER_H_
#define PATHFINDER_H_

#include "PathUnit.h"
#include "Cell.h"
#include <memory>

class Path
{
    public:

        Path();
        Path(std::shared_ptr<std::vector<std::vector<std::shared_ptr<Cell>>> >, int width, int height);
        ~Path();

        bool validPath(Cell,Cell);

        private:
        std::shared_ptr<std::vector<std::vector<std::shared_ptr<Cell>>>> matrix;
        std::shared_ptr<std::vector<PathUnit>> findPath(Cell, Cell);
        std::vector<PathUnit> validateNeighbors(std::vector<PathUnit>,std::vector<PathUnit>);
        std::vector<PathUnit> getShortestPath(std::vector<PathUnit>,int);
        int mapWidth;
        int mapHeight;

    };

#endif /* PATHFINDER_H_ */
