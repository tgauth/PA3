//
//  View.cpp
//  checkpointtres
//
//  Created by Tess Gauthier on 11/16/15.
//  Copyright © 2015 Tess Gauthier. All rights reserved.
//

#include <iostream>

using namespace std;

#include "View.h"

View::View()
{
    size = 11;
    scale = 2;
    origin = CartPoint();
    
}

View::~View()
{
    cout << "View destructed." << endl;
}

bool View::get_subscripts(int &ix, int &iy, CartPoint location)
{
    ix = (location.x - origin.x)/scale;
    iy = (location.y - origin.y)/scale;
    if (ix > view_maxsize || iy > view_maxsize)
    {
        cout << "An object is outside the display" << endl;
        return false;
    }
    else
        return true;
}

void View::clear()
{
    for (int i = 0; i < view_maxsize; i++)
    {
        for (int j = 0; j < view_maxsize; j++)
        {
            grid[i][j][0] = '.';
            grid[i][j][1] = ' ';
        }
    }
}

void View::plot(GameObject* ptr)
{
    int ix = 0;
    int iy = 0;
    if (get_subscripts(ix, iy, ptr->get_location()))
        {
            ptr->drawself(grid[ix][iy]);
        }
}

void View::draw()
{
    // initializes array for x and y axis
    int array[view_maxsize/2 + 1];
    for (int i = 0; i < view_maxsize/2; i++)
    {
        array[i] = 2*i;
    }
    array[view_maxsize/2] = view_maxsize;

    // prints y axis either from array or blank spaces
    for (int i = size -1; i >= 0; i--)
    {
        if (i%2 == 0)
        {
            cout << array[i];
            if (array[i] < 10)
            {
                cout << " ";
            }
        }
        else
        {
            cout << "  ";
        }

	// prints out grid of objects
        for (int j = 0 ; j < size; j++)
        {
            cout << grid[j][i][0];
            cout << grid[j][i][1];
            
        }
        cout << endl;
    }
    cout << "  ";

    // prints x axis
    for (int i = 0; i <= size; i++)
    {
        if (i%2 == 0)
        {
            cout << array[i];
            if (array[i] < 10)
            {
                cout << " ";
            }
        }
        else
        {
            cout << "  ";
        }
    }
    cout << endl;
}
