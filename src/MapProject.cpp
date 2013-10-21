//============================================================================
// Name        : MapProject.cpp
// Author      : Gary
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Map.h"
using namespace std;

int main()
{

    int columns = 0;
    int rows = 0;

    int startX = 0;
    int startY = 0;

    int endX = 0;
    int endY = 0;

    cout << "Welcome to the Map Editor!" << endl << endl;
    cout << "First, let's generate a map before we can edit it!" << endl;

    cout << "Please enter numbers between 1 and 10!" << endl;
    cout << "Length of map: ";
    cin >> columns;
    cout << "Width of map: ";
    cin >> rows;

    cout << "Generating a map of size " << columns << " x " << rows << " ..." << endl << endl;

    Map m(columns, rows);

    cout << "Define a start point" << endl;
    cout << "Start x: ";
    cin >> startX;
    cout << "Start y: ";
    cin >> startY;

    cout << "Define an end point" << endl;
    cout << "End x: ";
    cin >> endX;
    cout << "End y: ";
    cin >> endY;

    m.setStartCell(startX, startY);
    m.setEndCell(endX, endY);

    cout << endl << "Validating map..." << endl;
    bool isValid = m.isValidMap();

    if(!isValid)
    {
        cout << "Sorry! The map is not valid! Exiting Program...";
        return 0;
    }


    cout << endl << "Here's how the map looks like right now!" << endl;
    m.printMap();


    cout << endl << "What would you like to do now? (pick an option)" << endl;
    cout << "1 - Edit the map" << endl;
    // JUST TESTING
//    int columns = 10;
//    int rows = 10;
//
//    Map m(columns, rows);
//
//    m.setStartCell(0, 0);
//    m.setEndCell(9, 9);
//
//    m.printMap();

    return 0;
}
