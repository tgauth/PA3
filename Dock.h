//
//  Dock.hpp
//  PA_3
//
//  Created by Tess Gauthier on 11/8/15.
//  Copyright © 2015 Tess Gauthier. All rights reserved.
//

#include <iostream>

using namespace std;

#ifndef Dock_h
#define Dock_h
#include "GameObject.h"
#include "Sailor.h"
class Model;
class Sailor;
#include <stdio.h>

class Dock : public GameObject
{
private:
    double berths;
    
public:
    Dock(int in_id);
    Dock(int in_id, CartPoint in_loc);
    
    bool dock_boat(Sailor * sailor_to_dock);
    bool set_sail(Sailor * sailor_to_sail);
    bool update();
    void show_status();
    
    ~Dock();
};

#endif /* Dock_hpp */
