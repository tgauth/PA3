//
//  pa3.cpp
//  checkpointtres
//
//  Created by Tess Gauthier on 11/16/15.
//  Copyright © 2015 Tess Gauthier. All rights reserved.
//

#include <iostream>
#include <stdio.h>

#include "CartVector.h"
#include "CartPoint.h"
#include "GameObject.h"
#include "Port.h"
#include "Dock.h"
#include "Sailor.h"
#include "GameCommand.h"
#include "Model.h"

using namespace std;

void header();

int main()
{
    header();
    Model *model = new Model();
    View *view = new View();
    model->show_status();
    view->clear();
    
    int count = 0;
    char command;
    
    while (command != 'q')
    {
        if (count != 0 && (command == 'g' || command == 'r'))
            {
                do_list_command(*model);
            }
        model->display(*view);
        cout << "Enter command: ";
        cin >> command;
        
        switch (command)
        {
                case 's':
            {
                do_sail_command(*model);
                break;
            }
                case 'p':
            {
                do_port_command(*model);
                break;
            }
                case 'a':
            {
                do_anchor_command(*model);
                break;
            }
                case 'd':
            {
                do_dock_command(*model);
                break;
            }
                case 'h':
            {
                do_hide_command(*model);
                break;
            }
                case 'g':
            {
                do_go_command(*model);
                break;
            }
                case 'r':
            {
                do_run_command(*model);
                // repeat main loop
                break;
            }
        }
        count++;
    }
    cout << "Terminating Program" << endl;
    model->display(*view);
    view->~View();
    model->~Model();
    
    return 0;
}


void header()
{
    cout << "EC327: Introduction to Software Engineering" << endl;
    cout << "Fall 2015" << endl;
    cout<< "Programming Assignment 3" << endl;
}
