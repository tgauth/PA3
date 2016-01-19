//
//  Sailor.cpp
//  PA_3
//
//  Created by Tess Gauthier on 11/8/15.
//  Copyright © 2015 Tess Gauthier. All rights reserved.
//

#include <iostream>
#include "Sailor.h"

#include <math.h>

using namespace std;

Sailor::Sailor() : GameObject('S', 0)
{
    health = 25;
    size = 15;
    hold = 100;
    cargo = 0;
    state = 'a';
    hideout = NULL;
    port = NULL;
    dock = NULL;
    cout << "Sailor default constructed" << endl;
}

Sailor::Sailor(int in_id) : GameObject('S', in_id)
{
    health = 25;
    size = 15;
    hold = 100;
    cargo = 0;
    state = 'a';
    hideout = NULL;
    port = NULL;
    dock = NULL;
    cout << "Sailor default constructed" << endl;
}

Sailor::Sailor(int in_id, Dock* hideout) : GameObject('S', in_id, hideout->get_location())
{
    health = 25;
    size = 15;
    hold = 100;
    cargo = 0;
    state = 'h';
    this->hideout = hideout;
    dock = hideout;
    port = NULL;
    destination = hideout->get_location();
    cout << "Sailor constructed" << endl;
}

bool Sailor::update_location()
{
  // checks if Sailor is within one step of their destination
   if ((fabs(destination.x - get_location().x) <= fabs(delta.x)) && (fabs(destination.y - get_location().y) <= fabs(delta.y)))
        {
            location = destination;
            cout << display_code << get_id() << ": I'm there!" << endl;
            return true;
        }
    else
        {
            location = location + delta;
            
            // output message only if sailor is moving
            if (delta.x !=0)
            {
            cout << display_code << get_id() << ": Just keep sailing..." << endl;
            }
            return false;
        }
    return 0;
}

void Sailor::setup_destination(CartPoint dest)
{
    this->destination = dest;
    if (cart_distance(destination, get_location()) == 0)
    {
        delta.x = 0;
        delta.y = 0;
    }
    else
    {
    this->delta = (destination - get_location()) * (get_speed()/cart_distance(destination, get_location()));
    }
}

bool Sailor::update()
{
    bool check;
    
    switch (state)
    {
case 'a':
    {
        return false;
    }
case 's':
    {
        check = update_location();
        if (check == true)
        {
            state = 'a';
            return true;
        }
        else
            return false;
    }
case 'o':
    {
        check = update_location();
        if (check == true)
        {
            cout << "Starting to supply at a port" << endl;
            state = 'l';
            return true;
        }
        else
            return false;
    }
case 'i':
    {
        check = update_location();
        if (check == true)
        {
            cout << display_code << get_id() << ": Starting to unload at a dock" << endl;
            state = 'u';
            return true;
        }
        else
            return false;
    }
case 'l':
        {
	    // if boat is full, it cannot get supplies
            if (cargo == hold)
            {
                state = 'a';
                cout << display_code << get_id() << ": My boat is filled up. Send me to a Dock to unload. Dropping anchor" << endl;
                return true;
            }
            // if the port is not empty, it can provide supplies
            if (!port->is_empty())
            {
                double supplies;
                supplies = port->provide_supplies();
		// if the supplies provided by the port is greater than the room left in the boat
                if (supplies >= (hold-cargo))
                {
                    cargo = hold;
                    cout << display_code << get_id() << ": My new cargo is " << cargo << endl;
                    return false;
                }
		// if there is enough room in the boat, the supplies are simply added to the cargo
                else
                {
                    cargo = cargo + supplies;
                    cout << display_code << get_id() << ": My new cargo is " << cargo << endl;
                    return false;
                }
            }
            else
            {
                cout << display_code <<
                get_id() << ": This Port has no more supplies for me. Dropping anchor" << endl;
                state = 'a';
                return true;
            }
                
            return false;
        }
    case 'u':
        {
            bool result;
            result = dock->dock_boat(this);
            if (result)
            {
                state = 'd';
                cout << display_code << get_id() << ": I am unloading at the dock" << endl;
                presize = size;
                if (cargo > 0)
                {
                    size += 5;
                    hold += 20;
                    cargo = 0;
                }
            }
            else
            {
                state = 't';
                cout << display_code << get_id() << ": Help! My home dock is full" << endl;
            }
            return true;
        }
    case 'd':
        {
            return false;
        }
    case 'h':
        {
            check = update_location();
            if (check == true)
            {
                state = 'a';
                return true;
            }
            else
	      // cout << display_code << get_id() << ": Is going to hide at Dock " << hideout->get_id() << endl;
                return false;
        }
    case 't':
        {
            return false;
        }
    }
    return false;
}

double Sailor::get_size()
{
    return size;
}

double Sailor::get_cargo()
{
    return cargo;
}

void Sailor::start_sailing(CartPoint dest)
{
    setup_destination(dest);
    // if you are in docked state
    if (state == 'd')
    {
        int sail;
        sail = dock->set_sail(this);
    }
    state = 's';
    cout << "Sailing " << get_id() << " to (" << destination.x << ", " << destination.y << ")" << endl;
    cout << display_code << get_id() << ": On my way" << endl;
}

void Sailor::start_supplying(Port *destport)
{
    if (state == 'd')
    {
        dock->set_sail(this);
    }
    port = destport;
    setup_destination(port->get_location());
    state = 'o';
    cout << "Sailor " << get_id() << " supplying at Port " << port->get_id() << " and going to Port " << destport->get_id() << endl;
    cout << display_code << get_id() << ": Supplies here I come!" << endl;
}

void Sailor::start_hiding()
{
    if (state == 'd')
    {
        dock->set_sail(this);
    }
    setup_destination(hideout->get_location());
    state = 'h';
    cout << "Sailor " << get_id() << " hiding " << get_id() << endl;
    cout << display_code << get_id() << ": Off to hide" << endl;
}

bool Sailor::is_hidden()
{
    if (hideout == dock)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Sailor::start_docking(Dock *destDock)
{
    if (state == 'd')
    {
        dock->set_sail(this);
    }
    dock = destDock;
    setup_destination(destDock->get_location());
    state = 'i';
    cout << "Sailor " << get_id() << " sailing to Dock " << dock->get_id() << endl;
    cout << "S" << get_id() << ": Off to Dock" << endl;
}

void Sailor::anchor()
{
    state = 'a';
    cout << "Stopping " << get_id() << "" << endl;
    cout << display_code << get_id() << ": Dropping anchor" << endl;
}

void Sailor::show_status()
{
    switch (state)
    {
case 'a':
    {
        cout << "Sailor status: " << display_code << " with ID " << get_id() << " at location (" << get_location().x << ", " << get_location().y << ") is anchored";
        
        if (cart_distance(this->get_location(),hideout->get_location()) == 0)
        {
            cout << " (and hiding)";
        }
        
        cout << ". Has a size of: " << size << ", cargo of: " << cargo << ", hold of: " << hold << ", and health of: " << health << endl;
        break;
    }
case 's':
    {
       cout << "Sailor status: " << display_code << " with ID " << get_id() << " at location (" << get_location().x << ", " << get_location().y << " Has a speed of: " << get_speed() << " and is heading to: " << destination << endl;
        break;
    }
case 'o':
    {
        cout << "Sailor status: " << display_code << " with ID " << get_id() << " at location (" << get_location().x << ", " << get_location().y << ") is outbound to Port: " << port->get_id() << " with a speed of " << get_speed() << endl;
        break;
    }
case 'i':
    {
        cout << "Sailor status: " << display_code << " with ID " << get_id() << " at location (" << get_location().x << ", " << get_location().y << ") is inbound to Dock: " << dock->get_id() << " with a speed of " << get_speed() << endl;
        break;
    }
case 'l':
    {
        cout << "Sailor status: " << this->display_code << " with ID " << this->get_id() << " at location (" << this->get_location().x << ", " << this->get_location().y << ") is supplying at Port " << port->get_id() << endl;
        break;
    }
case 'u':
    {
        cout << "Sailor status: " << display_code << " with ID " << get_id() << " at location (" << get_location().x << ", " << get_location().y << ") is unloading at Dock " << dock->get_id() << endl;
        break;
    }
case 'd':
    {
        cout << "Sailor status: " << display_code << " with ID " << get_id() << " at location (" << get_location().x << ", " << get_location().y << ") is docked at Dock " << dock->get_id() << endl;
        break;
    }
case 't':
    {
        cout << "Sailor status: " << display_code << " with ID " << get_id() << " at location (" << get_location().x << ", " << get_location().y << ") is in trouble " << get_id() << endl;
        break;
    }
case 'h':
    {
        cout << "Sailor status: " << display_code << " with ID " << get_id() << " at location (" << get_location().x << ", " << get_location().y << ") is going to hide at Dock " << get_id() << endl;
        break;
    }
    }
}

double Sailor::get_speed()
{
    return (size-(cargo*.1));
}

Sailor::~Sailor()
{
    cout << "Sailor destructed." << endl;
}

double Sailor::get_presize()
{
    return presize;
}
