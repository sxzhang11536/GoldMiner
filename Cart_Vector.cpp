#include <iostream>
#include <cmath>
#include "Cart_Point.h"
#include "Cart_Vector.h"
using namespace std;

Cart_Vector::Cart_Vector()
{
	this->x = 0;
	this->y = 0;
}

Cart_Vector::Cart_Vector(double inputx, double inputy)
{
	this->x = inputx;
	this->y = inputy;
}

Cart_Vector operator* (const Cart_Vector& v1, const double& d)
{
	if (d == 0)
    {
        double newx = 0;
        double newy = 0;
        return Cart_Vector(newx, newy);
    }
    else
    {
    double newx = v1.x * d;
	double newy = v1.y * d;
	return Cart_Vector(newx, newy);
    }
}

Cart_Vector operator/ (const Cart_Vector& v1, const double& d)
{
	if (d==0)
	{
		double newx = v1.x;
		double newy = v1.y;
		return Cart_Vector(newx, newy);
	}
	else
	{
		double newx = (v1.x)/d;
		double newy = (v1.y)/d;
		return Cart_Vector(newx, newy);
	}
	
}

ostream& operator<<(ostream& os, const Cart_Vector& v1)
{
	os << "<" << v1.x << ", " << v1.y << ">";
	return os;

}
