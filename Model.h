//
//  Model.hpp
//  PA_3
//
//  Created by Tess Gauthier on 11/11/15.
//  Copyright © 2015 Tess Gauthier. All rights reserved.
//

#include <iostream>

using namespace std;

#ifndef Model_h
#define Model_h
#include "GameObject.h"
#include "Port.h"
#include "Sailor.h"
#include "Dock.h"
#include <stdio.h>
#include "View.h"

class Model
{
private:
    int time;
    GameObject** object_ptrs;
    int num_objects;
    Sailor** sailor_ptrs;
    int num_sailors;
    Dock** dock_ptrs;
    int num_docks;
    Port** port_ptrs;
    int num_ports;
    Model(const Model &other);
    
public:
    Model();
    ~Model();
    Sailor* get_Sailor_ptr(int id_num);
    Port* get_Port_ptr(int id_num);
    Dock* get_Dock_ptr(int id_num);
    bool update();
    void display(View& view);
    void show_status();
    
};

#endif /* Model_hpp */
