//
//  GameCommand.hpp
//  checkpointtres
//
//  Created by Tess Gauthier on 11/15/15.
//  Copyright © 2015 Tess Gauthier. All rights reserved.
//

#include <iostream>

using namespace std;

#ifndef GameCommand_h
#define GameCommand_h

#include <stdio.h>

#include "Model.h"

void do_sail_command(Model& model);
void do_go_command(Model& model);
void do_run_command(Model& model);
void do_port_command(Model& model);
void do_hide_command(Model& model);
void do_anchor_command(Model& model);
void do_list_command(Model& model);
void do_dock_command(Model& model);

#endif /* GameCommand_hpp */
