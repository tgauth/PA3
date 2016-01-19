//
//  Sailor.hpp
//  PA_3
//
//  Created by Tess Gauthier on 11/8/15.
//  Copyright © 2015 Tess Gauthier. All rights reserved.
//

#include <iostream>

using namespace std;

#ifndef Sailor_h
#define Sailor_h
#include "GameObject.h"
#include "Port.h"
#include "Dock.h"
class Dock;
class Port;
class CartPoint;
class CartVector;
class Model;

#include <stdio.h>

class Sailor : public GameObject
{
private:
  double health;
    double size;
    double presize;
    double hold;
    double cargo;
    CartPoint destination;
    CartVector delta;
    Port * port;
    Dock *  dock;
    Dock * hideout;
    
    bool update_location();
    void setup_destination(CartPoint dest);
    
public:
    Sailor();
    Sailor(int in_id);
    Sailor(int in_id, Dock* hideout);
    
    bool update();
    double get_size();
    double get_cargo();
    void start_sailing(CartPoint dest);
    void start_supplying(Port* destPort);
    void start_hiding();
    bool is_hidden();
    void start_docking(Dock* destDock);
    void anchor();
    void show_status();
    double get_speed();
    double get_presize();
    
    ~Sailor();
    
};

#endif /* Sailor_hpp */
