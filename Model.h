#ifndef MODEL_H
#define MODEL_H

#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Game_Object.h"
#include "Gold_Mine.h"
#include "Town_Hall.h"
#include "Person.h"
#include "Miner.h"
#include "View.h"
#include "Soldier.h"
#include <iostream>
#include <list>

using namespace std;

class Model
{
private:
    int time;
    /***
    Game_Object** object_ptrs;
    int num_objects;
    Miner** person_ptrs;
    int num_persons;
    Gold_Mine** mine_ptrs;
    int num_mines;
    Town_Hall** hall_ptrs;
    int num_halls;
     ***/
    
    list<Game_Object*> object_ptrs;
    list<Person*> person_ptrs;
    list<Gold_Mine*> mine_ptrs;
    list<Town_Hall*> hall_ptrs;
    list<Game_Object*> active_ptrs;
    
    
    
    
    //Model(const Model&);
    
public:
    Model();
    virtual ~Model();
    
    Person* get_Person_ptr(int);
    Gold_Mine* get_Gold_Mine_ptr(int);
    Town_Hall* get_Town_Hall_ptr(int);
    
    bool update();
    void display(View& view);
    void show_status();
    void handle_new_command(char,int,double,double);
    //void save(ofstream& file);
    //void restore(ifstream& file);
    
    
    
};


#endif
