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

// Forward references
int displayMainMenu();
void displayMapEditorMenu(Map*);
void processMenuRequest(int, Map*);
void processEditorOption(int, Map*);
int displayMainMenu()
{
    bool validOption = false;
    int choice = 0;
    do
    {
        cout << endl << " --- MAIN MENU --- " << endl;
        cout << endl << "What would you like to do now? (pick an option)" << endl;
        cout << "1 - Edit the map" << endl;
        cout << "2 - Validate the map (Check if the End is reachable from Start)" << endl;
        cout << "3 - Reset the map" << endl;
        cout << "4 - Display the map" << endl;
        cout << "5 - Exit" << endl;
        cout << "Choice: ";
        cin >> choice;

        if (choice > 0 && choice < 6)
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

void displayMapEditorMenu(Map * m)
{
    bool done = false;
    while (!done)
    {
        bool validOption = false;
        int choice = 0;

        do
        {
            cout << endl << " --- MAP EDITOR MENU --- " << endl;
            cout << "Please choose an option:" << endl;
            cout << "1 - Set Start point" << endl;
            cout << "2 - Set End point" << endl;
            cout << "3 - Change cell type" << endl;
            cout << "4 - Place item on a cell" << endl;
            cout << "5 - Return to main menu" << endl;
            cout << "Choice: ";
            cin >> choice;

            if (choice > 0 && choice <= 5)
            {
                validOption = true;
                if (choice == 5)
                {
                    done = true;
                }
            }
            else
            {
                cout << "Invalid choice! Please try again." << endl;
            }
        } while (!validOption);

        processEditorOption(choice, m);
    }
}

void processMenuRequest(int option, Map * m)
{
    if (option == 1)
    {
        displayMapEditorMenu(m);
    }
    else if (option == 2)
    {
        cout << "A map is valid if there is a path from Start to End." << endl;
        cout << "Validating the map..." << endl;
        if (m->isValidMap())
        {
            cout << "Congratulations! Your map is valid!" << endl;
        }
        else
        {
            cout << "The map is not valid. Consider editing it until it's valid." << endl;
        }
    }
    else if (option == 3)
    {
        cout << "Resetting map..." << endl;
        m->resetMap();
        cout << "Map is reset." << endl;

    }
    else if (option == 4)
    {
        cout << endl << "Here's how the map looks like right now!" << endl;
        m->printMap();
    }
    else if (option == 5)
    {
        cout << "Have a nice day!" << endl;
        return;
    }
    else if (option == 6)
    {
        cout << "Have a nice day!" << endl;
        return;
    }
    else if (option == 7)
    {
        cout << "Have a nice day!" << endl;
        return;
    }
    else if (option == 8)
    {
        cout << "Have a nice day!" << endl;
        return;
    }
    else if (option == 9)
    {
        cout << "Have a nice day!" << endl;
        return;
    }
    else if (option == 10)
    {
        cout << "Have a nice day!" << endl;
        return;
    }
}

void processEditorOption(int option, Map * m)
{
//    cout << "1 - Set Start point" << endl;
//    cout << "2 - Set End point" << endl;
//    cout << "3 - Change cell type" << endl;
//    cout << "4 - Place item on a cell" << endl;
    if (option == 1)
    {
        int startX = 0;
        int startY = 0;
        cout << "Start x = ";
        cin >> startX;
        cout << "Start y = ";
        cin >> startY;

        if (m->isValidCell(startX, startY))
        {
            m->setStartCell(startX, startY);
            cout << "The cell on coordinates (" << startX << ", " << startY << ") is now the start point.";
        }
        else
        {
            cout << "The coordinates (" << startX << ", " << startY << ") are not valid.";
        }
    }
    else if (option == 2)
    {
        int endX = 0;
        int endY = 0;
        cout << "End x = ";
        cin >> endX;
        cout << "End y = ";
        cin >> endY;

        if (m->isValidCell(endX, endY))
        {
            m->setEndCell(endX, endY);
            cout << "The cell on coordinates (" << endX << ", " << endY << ") is now the end point.";
        }
        else
        {
            cout << "The coordinates (" << endX << ", " << endY << ") are not valid.";
        }
    }
    else if (option == 3)
    {
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
    else if (option == 4)
    {
    }
    else if (option == 5)
    {
        cout << "Returning to main menu..." << endl;
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

    while (option != 5)
    {
        option = displayMainMenu();
        processMenuRequest(option, &m);
    }

    return 0;
}
