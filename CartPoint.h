//
//  CartPoint.hpp
//  PA_3
//
//  Created by Tess Gauthier on 11/3/15.
//  Copyright © 2015 Tess Gauthier. All rights reserved.
//
#include <iostream>


using namespace std;

#ifndef CartPoint_h
#define CartPoint_h
#include "CartVector.h"

#include <stdio.h>
class CartPoint
{
public:
    
    double x;
    double y;
    
    CartPoint();
    CartPoint(double in_x, double in_y);
    
    friend class Sailor;
    
};

double cart_distance(CartPoint p1, CartPoint p2);
bool cart_compare(CartPoint p1, CartPoint p2);

ostream& operator<<(ostream& out, const CartPoint& p1);
CartPoint& operator+(CartPoint p1, CartVector v1);
CartVector& operator-(CartPoint p1, CartPoint p2);

#endif /* CartPoint_hpp */
