/*
 * Map.h
 *
 *  Created on: Oct 21, 2013
 *      Author: Gary
 */

#ifndef MAP_H_
#define MAP_H_

#include "Cell.h"
#include "Path.h"
#include <memory>
#include <vector>
#include <algorithm>
#include <iostream>


class Map
{
    public:
        Map();
        Map(int,int);
        ~Map();

        // Map properties
        int getWidth();
        int getHeight();

        // Cell operations
        std::shared_ptr<Cell> getCell(int,int);
        std::shared_ptr<Cell> getStartCell();
        std::shared_ptr<Cell> getEndCell();
        void setCell(Cell::CellType,int,int);
        void setStartCell(int,int);
        void setEndCell(int,int);

        // Validations
        bool isValidMap();
        bool isValidPath(Cell, Cell);
        bool isValidCell(Cell);
        bool isValidCell(int,int);

        // Path
        //std::vector<PathUnit> findPath(Cell, Cell);


        // Test
        void printMap();
    private:
        std::vector<std::vector<std::shared_ptr<Cell>>> matrix;
        int mapWidth;
        int mapHeight;
};

#endif /* MAP_H_ */
