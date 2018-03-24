#include <iostream>
#include <stdio.h>
#include <math.h>
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Game_Object.h"
#include "Gold_Mine.h"
#include "Town_Hall.h"
#include "Person.h"
using namespace std;
//default
Person::Person()
{
    state = 's';


}

Person::Person(char in_code): Game_Object(in_code, 1)
{
    state = 's';
    speed = 5;
    display_code = in_code;
    health = 5;
    cout << "Person default constructed." << endl;
}

Person::Person(char in_code, int in_id, Cart_Point in_loc):Game_Object(in_code, in_id, in_loc)
{
    state = 's';
    speed = 5;
    health=5;
    cout << "Person constructed." << endl;
}
//destructor
Person::~Person()
{
    cout << "Person destructed." << endl;
}

bool Person::update_location()
{
    Cart_Vector displacement = destination - location;
    if ((fabs(displacement.x) <= fabs(delta.x)) && (fabs(displacement.y) <= fabs(delta.y))) //arrived
    {
        location = destination;
        cout << display_code << get_id() << ": I'm there!" << endl;
        return true;
    }
    else //on the road
    {
        location = location + delta;
        cout << display_code << get_id() << ":step..." << endl;
        return false;
        
    }
    
}

void Person::setup_destination(Cart_Point dest)
{
    destination = dest;
    double d = cart_distance(destination, location);
    if (d == 0) //distance to destinaiton is 0
    {
        delta.x = 0;
        delta.y = 0;
    }
    else
    {
        delta = (destination - location) * (speed/d);
    }
    
}

bool Person::is_alive()
{
    if (state == 'x')
    {
        return false;
    }
    else
    {
        return true;
    }
}

void Person::start_moving(Cart_Point dest) //tell the person to start moving
{
    if (is_alive())
    {
        setup_destination(dest);//setup destination
        state = 'm';//change state
        cout << "Moving " << get_id() << " to " << dest <<endl;
        if (delta.x == 0 && delta.y == 0)//arrived
        {
            cout << display_code << get_id() << ": I'm already there. see?" << endl;
        }
        else
        {
            cout << display_code << get_id() << ": On my way." << endl;
        }
    }
    else
    {
        cout << display_code << get_id() << "is dead. Cannot move." << endl;
    }
}


void Person::stop() //tell the person to stop
{
    state = 's';
    //cout << "Stopping " << get_id() << "." << endl;
    cout << "Stopping " << display_code << get_id() << endl;
    cout << display_code << get_id() << ": All right." << endl;
    
}

void Person::show_status()//show status
{
    switch (state)
    {
    case 's': //stopped
        cout << " is stopped." << endl;
        //cout << display_code << get_id() << ": All right." << endl;
            break;
    case 'm': //moving to a destination
        cout << " moving at speed of " << speed << " towards "<< destination << " at each step of "<< delta << " with health of "<< health << endl;
            break;
    case 'o': //outbound mining
        cout << " moving at speed of " << speed << " towards "<< destination << " at each step of "<< delta << " with health of "<< health << endl;
            break;
    case 'g': //getting gold
        cout << " moving at speed of " << speed << " towards "<< destination << " at each step of "<< delta << " with health of "<< health << endl;
            break;
//    case 'i': //inbound mining
//        cout << "Inbound to home with load: " << amount << endl;
//            break;
//    case 'd': //depositing gold
//        cout << "Depositing gold." << endl;
//            break;
    case 'x':
            cout << " is dead." <<endl;
    }
}

void Person::start_mining(Gold_Mine*, Town_Hall*)
{
    cout << "Sorry, I can't work a mine." << endl;
}



int Person::get_health()
{
    return health;
}

void Person::take_hit(int attack_strength, Person* attacker)//Person* target//
{
    health = health - attack_strength;
    if (health <= 0)
    {
        cout << display_code << get_id() << ": Ahhhh, I am dying." << endl;
        state = 'x';
    }
    else
    {
        cout << display_code << get_id() << ": Ouch!" << endl;
        
    }
    if (display_code != 's' && display_code != 'S' && state != 'x')
    {
        cout << display_code << get_id() << ": I don't wanna fight!" <<endl;
        Cart_Vector v = this->get_location() - attacker->get_location();
	if (v.x != 0 && v.y != 0)
	{
        Cart_Point newdestination = this->get_location() + v*1.5;
        start_moving(newdestination);
	}
	else
	{
	v.x = 1;
	v.y = 1;
	Cart_Point newdestination = this->get_location() + v*1.5;
        start_moving(newdestination);
	}



    }
}

void Person::start_attack(Person* target)
{
    cout << display_code << this->get_id() << ": I can't attack." << endl;
}
