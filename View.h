//
//  View.hpp
//  checkpointtres
//
//  Created by Tess Gauthier on 11/16/15.
//  Copyright © 2015 Tess Gauthier. All rights reserved.
//

#include <iostream>

using namespace std;

#ifndef View_h
#define View_h

#include <stdio.h>
#include "CartPoint.h"
#include "GameObject.h"


const int view_maxsize = 20;

class View
{
private:
    int size;
    double scale;
    CartPoint origin;
    char grid[view_maxsize][view_maxsize][2];
    bool get_subscripts(int &ix, int &iy, CartPoint location);
    
public:
    View();
    ~View();
    void clear();
    void plot(GameObject* ptr);
    void draw();
    
    friend void GameObject::drawself(char* grid);
    friend class Model;
    
};

#endif /* View_hpp */
