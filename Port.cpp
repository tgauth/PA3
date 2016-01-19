//
//  Port.cpp
//  PA_3
//
//  Created by Tess Gauthier on 11/7/15.
//  Copyright © 2015 Tess Gauthier. All rights reserved.
//

#include <iostream>
#include "Port.h"

using namespace std;

Port::Port(int in_id):GameObject('P', in_id)
{
    state = 'f';
    inventory = 500;
    cout << "Port default constructed" << endl;
}

Port::Port(int in_id, CartPoint in_loc):GameObject('P', in_id, in_loc)
{
    state = 'f';
    inventory = 500;
    cout << "Port constructed" << endl;
}

bool Port::is_empty()
{
    if (inventory == 0)
        return true;
    else
        return false;
}

double Port::provide_supplies(double amount_to_provide)
{
    if (inventory >= amount_to_provide)
    {
        inventory = inventory - amount_to_provide;
        return amount_to_provide;
    }
    else
    {
        amount_to_provide = 0;
        return inventory;
    }
}

bool Port::update()
{
    if ((is_empty() && (state != 'e')) == true)
        {
            state = 'e';
            display_code = 'p';
            cout << "Port " << get_id() << "has been depleted of supplies" << endl;
            return true;
        }
    else
    {
        return false;
    }
}

void Port::show_status()
{
    cout << "Port Status: " << display_code << " with ID " << get_id() << " at location (" << get_location().x  << ", " << get_location().y << ") containing supplies " << inventory << endl;
}

Port::~Port()
{
    cout << "Port destructed." << endl;
}

