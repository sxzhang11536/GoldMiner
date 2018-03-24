#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Game_Object.h"
#include "Gold_Mine.h"
#include "Town_Hall.h"

using namespace std;

class Person: public Game_Object
{
private:
    double speed;
    Cart_Point destination;
    Cart_Vector delta;
    int health;

    
protected:
    bool update_location();
    void setup_destination(Cart_Point);
    
public:
    Person();
    Person(char);
    Person (char, int, Cart_Point);
    virtual ~Person();
    
    void start_moving(Cart_Point);
    void stop();
    void show_status();
    virtual void start_mining(Gold_Mine*, Town_Hall*);
    bool is_alive();
    virtual void take_hit(int, Person*); //
    virtual void start_attack(Person*);
    int get_health();
    
    
};
#endif
