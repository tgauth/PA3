//
//  Dock.cpp
//  PA_3
//
//  Created by Tess Gauthier on 11/8/15.
//  Copyright © 2015 Tess Gauthier. All rights reserved.
//
#include <iostream>

#include "Dock.h"

using namespace std;

Dock::Dock(int in_id) : GameObject('d', in_id)
{
    berths = 30;
    state = 'u';
    cout << "Dock default constructed" << endl;
}

Dock::Dock(int in_id, CartPoint in_loc) : GameObject('d', in_id, in_loc)
{
    berths = 30;
    state = 'u';
    cout << "Dock constructed" << endl;
}

bool Dock::dock_boat(Sailor *sailor_to_dock)
{
    if (sailor_to_dock->get_size() <= berths)
    {
        berths = berths - sailor_to_dock->get_size();
        return true;
    }
    else
    {
        return false;
    }
}

bool Dock::set_sail(Sailor *sailor_to_dock)
{
    if (sailor_to_dock->get_cargo() == 0)
    {
        berths = berths + sailor_to_dock->get_presize();
        return true;
    }
    else
    {
        return false;
    }
}

bool Dock::update()
{
    // check the only return true when packed/unpacked
    if (berths == 0)
    {
        state = 'p';
        display_code = 'D';
        cout << "Dock " << get_id() << " is packed" << endl;
        return true;
    }
    else if (berths > 0)
    {
        if (state == 'p')
        {
            display_code = 'd';
            state = 'u';
            return false;
        }
        else
        {
        return false;
        }
    }
    return false;
}

void Dock::show_status()
{
   cout << "Dock Status: " << this->display_code << " with ID " << this->get_id() << " at location (" << this->get_location().x << ", " << this->get_location().y << ") has " << berths << " berths" << endl;
}

Dock::~Dock()
{
    cout << "Dock destructed." << endl;
}
