#ifndef CART_VECTOR_H
#define CART_VECTOR_H
#include <iostream>
using namespace std;

class Cart_Vector
{
public:
	double x, y;
	Cart_Vector();
	Cart_Vector(double,double);
};

Cart_Vector operator* (const Cart_Vector& v1, const double& d);
Cart_Vector operator/ (const Cart_Vector& v1, const double& d);

ostream& operator<< (ostream& os, const Cart_Vector& v1);
#endif
