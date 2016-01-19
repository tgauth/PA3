//
//  CartPoint.cpp
//  PA_3
//
//  Created by Tess Gauthier on 11/3/15.
//  Copyright © 2015 Tess Gauthier. All rights reserved.
//

#include <iostream>
#include "CartPoint.h"
#include "cmath"

using namespace std;

CartPoint::CartPoint()
{
    x = 0;
    y = 0;
}

CartPoint::CartPoint(double in_x, double in_y)
{
    x = in_x;
    y = in_y;
}

double cart_distance(CartPoint p1, CartPoint p2)
    {
        double xdistance;
        double ydistance;
        xdistance = p1.x - p2.x;
        ydistance = p1.y - p2.y;
        double distance;
        distance = sqrt(xdistance*xdistance + ydistance*ydistance);
        return distance;
    }

bool cart_compare(CartPoint p1, CartPoint p2)
    {
        if ((p1.x = p2.x) && (p1.y = p2.y))
        {
            return true;
        }
        else
            return false;
    }
    
ostream& operator<<(ostream& out, const CartPoint& p1)
{
    out << "(" << p1.x << ", " << p1.y << ")";
    return out;
}

CartPoint& operator+(CartPoint p1, CartVector v1)
{
    double x = p1.x + v1.x;
    double y = p1.y + v1.y;
    CartPoint * p2 = new CartPoint(x,y);
    return *p2;
}

CartVector& operator-(CartPoint p1, CartPoint p2)
{
    double x = p1.x - p2.x;
    double y = p1.y - p2.y;
    CartVector * v1 = new CartVector(x,y);
    return *v1;
}
