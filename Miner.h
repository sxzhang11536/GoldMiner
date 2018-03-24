#ifndef MINER_H
#define MINER_H

#include <iostream>
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Game_Object.h"
#include "Gold_Mine.h"
#include "Town_Hall.h"
#include "Person.h"

using namespace std;

class Miner: public Person
{
private:
    double amount;
    Gold_Mine* mine;
    Town_Hall* home;

public:
    Miner();
    Miner(int, Cart_Point);
    virtual~Miner();
    
    bool update();
    void start_mining(Gold_Mine*, Town_Hall*);
    void show_status();
    
    
};

#endif
