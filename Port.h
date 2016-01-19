//
//  Port.hpp
//  PA_3
//
//  Created by Tess Gauthier on 11/7/15.
//  Copyright © 2015 Tess Gauthier. All rights reserved.
//

#ifndef Port_h
#define Port_h

#include <stdio.h>
#include "GameObject.h"
class Model;

class Port: public GameObject
{
private:
    double inventory;
    
public:
    
    Port(int in_id);
    Port(int in_id, CartPoint in_loc);
    
    bool is_empty();
    double provide_supplies(double amount_to_provide = 50);
    bool update();
    void show_status();
    
    ~Port();
    
};
#endif /* Port_hpp */
