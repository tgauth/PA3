//
//  GameObject.cpp
//  PA_3
//
//  Created by Tess Gauthier on 11/7/15.
//  Copyright © 2015 Tess Gauthier. All rights reserved.
//

#include <iostream>

#include "GameObject.h"

using namespace std;

GameObject::GameObject(char in_code, int in_id)
{
    display_code = in_code;
    id_num = in_id;
    location = CartPoint();
    cout << "GameObject default constructed" << endl;
}

GameObject::GameObject(char in_code, int in_id, CartPoint in_loc)
{
    display_code = in_code;
    id_num = in_id;
    location = in_loc;
    cout << "GameObject constructed" << endl;
}

CartPoint GameObject::get_location()
{
    return location;
}

int GameObject::get_id()
{
    return id_num;
}

void GameObject::show_status()
{
    // update to match sample output
    cout << "<" << display_code << "> with ID <" << id_num << "> at location <" << location << ">" << endl;
}

GameObject::~GameObject()
{
    cout << "GameObject destructed" << endl;
}

bool GameObject::update()
{
    // what happens here
    return true;
}

void GameObject::drawself(char* grid)
{
    if (*grid == '.')
    {
        *grid = this->display_code;
        *(grid+1) = this->get_id() + 48;
    }
    else
    {
        *grid = '*';
        *(grid+1) = ' ';
    }
}
