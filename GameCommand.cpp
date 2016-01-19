//
//  GameCommand.cpp
//  checkpointtres
//
//  Created by Tess Gauthier on 11/15/15.
//  Copyright © 2015 Tess Gauthier. All rights reserved.
//

#include <iostream>

using namespace std;

#include "GameCommand.h"

// add echo information for output redirection

void do_sail_command(Model& model)
{
    int ID;
    cin >> ID;
    double x;
    cin >> x;
    double y;
    cin >> y;
    model.get_Sailor_ptr(ID)->start_sailing(CartPoint(x,y));
}

void do_go_command(Model& model)
{
    cout << "Advancing time one tick" << endl;
    bool result;
    result = model.update();
}

void do_run_command(Model& model)
{
    cout << "Advancing to next event or 5 ticks" << endl;
    int count = 0;
    bool result = false;
    while (count < 5 && result == false)
    {
        result = model.update();
        count ++;
    }
    
}
void do_port_command(Model& model)
{
    int ID1;
    int ID2;
    cin >> ID1 >> ID2;
    model.get_Sailor_ptr(ID1)->start_supplying(model.get_Port_ptr(ID2));
}

void do_hide_command(Model& model)
{
    int ID1;
    cin >> ID1;
    model.get_Sailor_ptr(ID1)->start_hiding();
}

void do_anchor_command(Model& model)
{
    int ID1;
    cin >> ID1;
    model.get_Sailor_ptr(ID1)->anchor();
}

void do_list_command(Model& model)
{
    model.show_status();
}

void do_dock_command(Model& model)
{
    int ID1;
    cin >> ID1;
    int ID2;
    cin >> ID2;
    model.get_Sailor_ptr(ID1)->start_docking(model.get_Dock_ptr(ID2));
}
