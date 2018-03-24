#ifndef SOLDIER_H
#define SOLDIER_H

#include <iostream>
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Game_Object.h"
#include "Gold_Mine.h"
#include "Town_Hall.h"
#include "Person.h"

class Soldier: public Person
{
private:
    int attack_strength;
    double range;
    Person* target;
    
public:
    Soldier();
    Soldier(int, Cart_Point);
    ~Soldier();
    void start_attack(Person*);
    bool update();
    void show_status();
    void take_hit(int, Person*);
};

#endif
