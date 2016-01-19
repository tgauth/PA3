//
//  CartVector.hpp
//  PA_3
//
//  Created by Tess Gauthier on 11/3/15.
//  Copyright © 2015 Tess Gauthier. All rights reserved.
//

#include <iostream>

using namespace std;

#ifndef CartVector_h
#define CartVector_h
class CartPoint;
#include <stdio.h>
class CartVector
{
public:
    
    double x;
    double y;

    CartVector();
    CartVector(double in_x, double in_y);
    
    friend class Sailor;
    
};

CartPoint& operator+(CartPoint p1, CartVector v1);
CartVector& operator-(CartPoint p1, CartPoint p2);
ostream& operator<<(ostream& out, const CartVector& p1);
CartVector& operator*(CartVector v1, double d);
CartVector& operator/(CartVector v1, double d);


#endif /* CartVector_hpp */
