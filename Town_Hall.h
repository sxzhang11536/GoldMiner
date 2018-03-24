#ifndef TOWN_HALL_H
#define TOWN_HALL_H

#include <iostream>
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Game_Object.h"
using namespace std;

class Town_Hall: public Game_Object
{
private:
    double amount;

public:
    Town_Hall();
    Town_Hall(int, Cart_Point);
    ~Town_Hall();
    
    void deposit_gold(double);
    bool update();
    void show_status();
};

#endif
