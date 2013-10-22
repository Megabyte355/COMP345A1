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

// Forward declarations
int displayMainMenu();
void processMenuRequest(int, Map*);

int displayMainMenu()
{
    bool validOption = false;
    int choice = 0;
    do
    {
        cout << endl << " --- MAIN MENU --- " << endl;
        cout << endl << "What would you like to do now? (pick an option)" << endl;
        cout << "1 - Display the map" << endl;
        cout << "2 - Validate the map (Check if the End is reachable from Start)" << endl;
        cout << "3 - Set Start point" << endl;
        cout << "4 - Set End point" << endl;
        cout << "5 - Change a cell's type" << endl;
        cout << "6 - Place item on a cell" << endl;
        cout << "7 - Reset the map" << endl;
        cout << "8 - Exit" << endl;
        cout << "Choice: ";
        cin >> choice;

        if (choice > 0 && choice <= 8)
        {
            validOption = true;
        }
        else
        {
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (!validOption);

    return choice;
}

void processMenuRequest(int option, Map * m)
{
    if (option == 1)
    {
        // Display the map
        cout << endl << "Here's how the map looks like right now!" << endl;
        m->printMap();
    }
    else if (option == 2)
    {
        // Validate the map
        // NOTICE: A map is valid if there is a path from Start to End.
        cout << "Validating the map..." << endl;
        if (m->isValidMap())
        {
            cout << "Congratulations! Your map is valid!" << endl;
        }
        else
        {
            cout << "ALERT!!!" << endl;
            cout << "Unable to find a path from Start to End!" << endl;
        }
    }
    else if (option == 3)
    {
        // Set Start point
        int startX = 0;
        int startY = 0;
        cout << "Start x = ";
        cin >> startX;
        cout << "Start y = ";
        cin >> startY;

        if (m->isValidCell(startX, startY))
        {
            m->setStartCell(startX, startY);
            cout << "The cell on coordinates (" << startX << ", " << startY << ") is now the start point." << endl;
        }
        else
        {
            cout << "The coordinates (" << startX << ", " << startY << ") are not valid." << endl;
        }
    }
    else if (option == 4)
    {
        // Set End point
        int endX = 0;
        int endY = 0;
        cout << "End x = ";
        cin >> endX;
        cout << "End y = ";
        cin >> endY;

        if (m->isValidCell(endX, endY))
        {
            m->setEndCell(endX, endY);
            cout << "The cell on coordinates (" << endX << ", " << endY << ") is now the end point." << endl;
        }
        else
        {
            cout << "The coordinates (" << endX << ", " << endY << ") are not valid." << endl;
        }
    }
    else if (option == 5)
    {
        // Change cell type
        int x = 0;
        int y = 0;
        cout << "Enter coordinates of cell to be changed:" << endl;
        cout << "x = ";
        cin >> x;
        cout << "y = ";
        cin >> y;

        if (m->isValidCell(x, y))
        {
            int cellChoice = 0;
            cout << "Choose a cell type:" << endl;
            cout << "1 - Wall" << endl;
            cout << "2 - Surface" << endl;
            cout << "3 - Empty" << endl;
            cin >> cellChoice;

            if (cellChoice == 1)
            {
                m->getCell(x, y)->setType(Cell::CellType::Wall);
            }
            else if (cellChoice == 2)
            {
                m->getCell(x, y)->setType(Cell::CellType::Surface);
            }
            else if (cellChoice == 3)
            {
                m->getCell(x, y)->setType(Cell::CellType::Empty);
            }
            else
            {
                cout << "Invalid cell type option." << endl;
            }
        }
        else
        {
            cout << "The coordinates (" << x << ", " << y << ") are not valid.";
        }
    }
    else if (option == 6)
    {
        // Place an item
    }
    else if (option == 7)
    {
        // Reset map
        cout << "Resetting map..." << endl;
        m->resetMap();
        cout << "Map is reset." << endl;
    }
    else
    {
        // Option 8 - Exit
        cout << "Have a nice day!" << endl;
    }
}

int main()
{
    int columns = 0;
    int rows = 0;

    cout << "Welcome to the Map Editor!" << endl << endl;
    cout << "First, let's generate a map of fixed size!" << endl;

    cout << "Please enter numbers between 1 and 10!" << endl;
    cout << "Length of map: ";
    cin >> columns;
    cout << "Width of map: ";
    cin >> rows;

    cout << "Generating a map of size " << columns << " x " << rows << " ..." << endl << endl;

    Map m(columns, rows);

    int option = 0;

    while (option != 8)
    {
        option = displayMainMenu();
        processMenuRequest(option, &m);
    }

    return 0;
}
