#include <iostream>
#include <cmath>
#include "Cart_Point.h"
#include "Cart_Vector.h"
using namespace std;

//default constructor
Cart_Point::Cart_Point()
{
	this->x = 0;
	this->y = 0;
}

Cart_Point::Cart_Point(double inputx, double inputy)
{
	this->x = inputx;
	this->y = inputy;
}

//distance between vectors
double cart_distance(Cart_Point p1, Cart_Point p2)
{
	return sqrt (pow(p2.x-p1.x, 2)+pow(p2.y-p1.y, 2));
}

//overloading <<
ostream& operator<<(ostream& os, const Cart_Point& p1)
{
	os << "(" << p1.x << ", " << p1.y << ")";
	return os;

}

//overloading +
Cart_Point operator+(const Cart_Point& p1, const Cart_Vector& v1)
{
	double newx = p1.x + v1.x;
	double newy = p1.y + v1.y;
	return Cart_Point(newx, newy);
}

//overloading -
Cart_Vector operator- (const Cart_Point& p1, const Cart_Point& p2)
{
	double newx = p1.x - p2.x;
	double newy = p1.y - p2.y;
	return Cart_Vector(newx, newy);
}
