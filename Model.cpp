//
//  Model.cpp
//  PA_3
//
//  Created by Tess Gauthier on 11/11/15.
//  Copyright © 2015 Tess Gauthier. All rights reserved.
//

#include <iostream>

using namespace std;

#include "Model.h"

Model::Model()
{
    time = 0;
    
    this->dock_ptrs = new Dock*[3];
    this->port_ptrs = new Port*[4];
    this->sailor_ptrs = new Sailor*[3];
    this->object_ptrs = new GameObject*[10];
    
    this->dock_ptrs[0] = new Dock(1, CartPoint(5,1));
    this->object_ptrs[0] = dock_ptrs[0];
    this->dock_ptrs[1] = new Dock(2, CartPoint(6,2));
    this->object_ptrs[1] = dock_ptrs[1];
    this->dock_ptrs[2] = new Dock(3, CartPoint(1,8));
    this->object_ptrs[2] = dock_ptrs[2];
    this->port_ptrs[0] = new Port(1, CartPoint(1,20));
    this->object_ptrs[6] = port_ptrs[0];
    this->port_ptrs[1] = new Port(2, CartPoint(20,1));
    this->object_ptrs[7] = port_ptrs[1];
    this->port_ptrs[2] = new Port(3, CartPoint(20,20));
    this->object_ptrs[8] = port_ptrs[2];
    this->port_ptrs[3] = new Port(4, CartPoint(7,2));
    this->object_ptrs[9] = port_ptrs[3];
    this->sailor_ptrs[0] = new Sailor(1, dock_ptrs[0]);
    this->object_ptrs[3] = sailor_ptrs[0];
    this->sailor_ptrs[1] = new Sailor(2, dock_ptrs[1]);
    this->object_ptrs[4] = sailor_ptrs[1];
    this->sailor_ptrs[2] = new Sailor(3, dock_ptrs[2]);
    this->object_ptrs[5] = sailor_ptrs[2];
    
    num_objects = 10;
    num_sailors = 3;
    num_ports = 4;
    num_docks = 3;
    
    cout << "Model default constructed" << endl;
}

Model::~Model()
{
    for (int i = 0; i < 10; i++)
    {
        delete object_ptrs[i];
    }
    
    cout << "Model destructed" << endl;
}

Sailor* Model::get_Sailor_ptr(int id_num)
{
    for (int i = 0; i < num_sailors; i++)
    {
        if (sailor_ptrs[i]->get_id() == id_num)
        {
            return sailor_ptrs[i];
        }
    }
    return NULL;
}

Port* Model::get_Port_ptr(int id_num)
{
    for (int i = 0; i < num_ports; i++)
    {
        if (port_ptrs[i]->get_id() == id_num)
        {
            return port_ptrs[i];
        }
    }
    return NULL;
}

Dock* Model::get_Dock_ptr(int id_num)
{
    for (int i = 0; i < num_docks; i++)
    {
        if (dock_ptrs[i]->get_id() == id_num)
        {
            return dock_ptrs[i];
        }
    }
    return NULL;
}

bool Model::update()
{
    // keeps track of the amount of objects updated
    int count = 0;
    // stores return of update of objects
    bool result;
    
    time += 1;
    for (int i = 0; i < num_objects; i++)
    {
        result = object_ptrs[i]->update();
        if (result == true)
        {
            count += 1;
        }
    }
    if (count > 0)
    {
    return true;
    }
    else
    return false;
}

void Model::display(View& view)
{
    cout << "Time: " << time << endl;
    view.clear();
    for (int i = 0; i < num_objects; i++)
    {
        view.plot(object_ptrs[i]);
    }
    view.draw();
}

void Model::show_status()
{
    for (int i = 0; i < num_objects; i++)
    {
        object_ptrs[i]->show_status();
    }
}

Model::Model(const Model &other)
{
    
}

             
