//
//  CartVector.cpp
//  PA_3
//
//  Created by Tess Gauthier on 11/3/15.
//  Copyright © 2015 Tess Gauthier. All rights reserved.
//

#include <iostream>
#include "CartVector.h"

using namespace std;

CartVector::CartVector()
    {
        x = 0;
        y = 0;
    }
    
CartVector::CartVector(double in_x, double in_y)
    {
        x = in_x;
        y = in_y;
    }
    
CartVector& operator*(CartVector v1, double d)
{
    double x = v1.x * d;
    double y = v1.y * d;
    CartVector * v2 = new CartVector(x,y);
    return *v2;
}

CartVector& operator/(CartVector v1, double d)
{
    if (d == 0)
    {
        CartVector * v2 = new CartVector(v1.x, v1.y);
        return * v2;
    }
    else
    {
        double x = v1.x / d;
        double y = v1.y / d;
        CartVector * v2 = new CartVector(x ,y);
        return *v2;
    }
}

ostream& operator<<(ostream& out, const CartVector& p1)
{
    out << "<" << p1.x << ", " << p1.y << ">";
    return out;
}
