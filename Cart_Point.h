#ifndef CART_POINT_H
#define CART_POINT_H

#include <iostream>
#include "Cart_Vector.h"
using namespace std;

class Cart_Point
{
public:
	double x, y;
	Cart_Point();
	Cart_Point(double, double);
};

//nonmember functions
double cart_distance(Cart_Point, Cart_Point);
double cart_distance(Cart_Point, Cart_Point);

//nonmember function overloading
ostream& operator<<(ostream& os, const Cart_Point& p1);
Cart_Point operator+ (const Cart_Point& p1, const Cart_Vector& v1);
Cart_Vector operator- (const Cart_Point& p1, const Cart_Point& p2);


#endif
