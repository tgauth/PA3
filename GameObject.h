//
//  GameObject.hpp
//  PA_3
//
//  Created by Tess Gauthier on 11/7/15.
//  Copyright © 2015 Tess Gauthier. All rights reserved.
//

#include <iostream>

using namespace std;

#ifndef GameObject_h
#define GameObject_h
#include "CartPoint.h"
#include <stdio.h>

class GameObject
{
private:
    int id_num;
    
protected:
    CartPoint location;
    char display_code;
    char state;
    
public:
    GameObject(char in_code, int in_id);
    GameObject(char in_code, int in_id, CartPoint in_loc);
    CartPoint get_location();
    int get_id();
    virtual void show_status();
    virtual bool update() = 0;
    virtual ~GameObject();
    void drawself(char* grid);
};


#endif /* GameObject_hpp */
