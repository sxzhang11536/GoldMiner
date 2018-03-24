#include <iostream>
#include "Game_Object.h"
#include "Miner.h"
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Gold_Mine.h"
#include "Town_Hall.h"
#include "Soldier.h"
#include "Person.h"
#include "Model.h"

using namespace std;

//default
Soldier::Soldier():Person('S')
{
    state = 's';
    attack_strength = 2;
    range = 2.0;
    //Miner* Miner0 = new Miner(0, Cart_Point(0, 0));
    target = NULL;
    cout << "Soldier default constructed." <<endl;
}

Soldier::Soldier(int in_id, Cart_Point in_loc):Person('S',in_id,in_loc)
{
    state = 's';
    attack_strength = 2;
    range = 2.0;
    //Miner* Miner0 = new Miner(0, Cart_Point(0, 0));
    target = NULL;
    cout << "Soldier constructed." << endl;
}

Soldier::~Soldier()
{
    cout << "Soldier destructed." << endl;
}

void Soldier::start_attack(Person* in_target)
{
    target = in_target;
    Cart_Point r = target->get_location();
    double dis = cart_distance(this->get_location(), r);
    if (dis <= 2)
    {
        if (is_alive()==false)
        {
            cout << display_code << get_id() << "I win." << endl;
        }
        else
        {
            cout << display_code << get_id()<< ": Attacking." << endl;
            state = 'a';
        }
    }
    else
    {
        cout << display_code << get_id()<< ":Target out of range." << endl;
        cout << display_code << get_id()<< ":Chaaaaarge." << endl;
    }
    
    
}

bool Soldier::update()
{
    if (this->get_health() < 3)
    {
        display_code = 's';
    }
        
    bool boo = false;
    switch (state)
    {
        case ('x'):
        {
            boo = false;
            break;
        }
        case('s'):
        {
            boo = false;
            break;
        }
        case ('m'):
        {
            if (update_location()) //arrived
            {
                state = 's';
                boo = true;
            }
            //else
            //{
            //    boo = false;
            //}
            break;
        }
        case ('a'):
        {
            double dis = cart_distance(this->get_location(), target->get_location());
            if (dis > 2)
            {
                cout << display_code << get_id() << ": Target out of range." << endl;
		cout << display_code << get_id() << ":Chaaaaarge." << endl;
                state = 's';
                boo = true;
                break;
            }
            else
            {
                if (target->is_alive()==false)
                {
                    cout << display_code << get_id() << ":I win." << endl;
                    state = 's';
                    boo = true;
                    break;
                }
                else
                {
                    cout << display_code << get_id() << ": Take that!" << endl;
                    target->take_hit(attack_strength, this);
                    boo = false;
                    break;
                }
                
            }
        }
    }return boo;
}

void Soldier::show_status()
{
    cout << "Soldier status: " << display_code << get_id() << " at " << location;
    
    if (state == 'a')
    {
        cout << " is attacking." << endl;
            
    }
    else if (state == 'x')
    {
        Person::show_status();
            
    }
    else
    {
        cout << " is stopped." << endl;
    }
}

void Soldier::take_hit(int attack_strength, Person* attacker)
{
    Person::take_hit(attack_strength, attacker);
    if (state != 'x')
    {
        //cout << "Take that!" << endl;
        start_attack(attacker);
    }
}
