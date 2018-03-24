#include <iostream>
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Game_Object.h"
#include "Gold_Mine.h"
#include "Town_Hall.h"
#include "Person.h"
#include "Miner.h"

using namespace std;

Miner::Miner():Person('M')  //inherit from person
{
    amount = 0;
    mine = NULL;
    home = NULL;
    //location = Cart_Point(0.0,0.0);
    //state = 's';
    cout << "Miner default constructed." << endl;
}

Miner::Miner(int in_id, Cart_Point in_loc):Person('M',in_id,in_loc)
{
    amount = 0;
    mine = NULL;
    home = NULL;
    //location = Cart_Point(0.0,0.0);
    cout << "Miner constructed." << endl;
    
}
//destructor
Miner::~Miner()
{
    cout << "Miner destructed." << endl;
}


void Miner::start_mining(Gold_Mine* inputMine, Town_Hall* inputHome)
{
    if(is_alive()==false)
    {
        cout << display_code << get_id() << "is dead. Cannot mine anymore" << endl;
    }
    else
    {
        mine = inputMine;
        home = inputHome;
        setup_destination(mine->get_location());//destination is the location of the mine it is heading to
        state = 'o';
        cout << "Miner " << get_id() << " is mining at Gold_Mine " << mine->get_id() << " and depositing at Town_Hall " << home->get_id() << "." << endl;
        cout << display_code << get_id() << ": Yes, my lord." << endl;
    }
}

bool Miner::update()
{
    if (this->get_health()<3)
    {
        display_code = 'm';
    }
    bool boo = false;
    switch (state)
    {
        case 's':
        {
            boo = false;
            break;
        }
        
        case 'm':
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
        
        case 'o':
        {
            if (update_location())
            {
                state = 'g';
                boo = true;
            }
            //else
          //  {
           //     boo = false;
           // }
            break;
        }
        
        case 'g':
        {
            this->amount = mine->dig_gold();
            cout << display_code << get_id() << ": Got " << this->amount << " gold." << endl;
            Cart_Point d = home->get_location();
            setup_destination(d); //set up destination for home
            state = 'i';
            boo = true;

            break;
        }
        
        case 'i':
        {
            if (update_location())
            {
                state = 'd';
                boo = true;
            }
       //     else
         //   {
       //         boo = false;
           // }
            break;
        }
        
        case 'd':
        {
            cout << display_code << get_id() << ": Deposit " << amount << "of gold." << endl;
            home->deposit_gold(amount);
            if (mine->is_empty())
            {
                state = 's';
                cout << display_code << get_id() << ": More work?"<< endl;
                boo = true;
            }
            else
            {
                Cart_Point d = mine->get_location();
                setup_destination(d);
                state = 'o';
                cout << display_code << get_id() << ": Going back for more." << endl;
                boo = true;
            }
            break;
        }
        case 'x':
        {
            boo = false;
            break;
        }
            
    }
    return boo;
    
    
}



void Miner::show_status()
{
    cout << "Miner status: " << display_code << get_id() << " at " << location;
    
    switch (state)
    {
        case 's': //stopped
            Person::show_status(); //call the function from person
            //cout << " is stopped." << endl;
            break;
        case 'm': //moving to a destination
            Person::show_status();
            break;
        case 'o': //outbound mining
            Person::show_status();
            break;
        case 'g': //getting gold
            Person::show_status();
            break;
        case 'i': //inbound mining
            cout << "Inbound to home with load: " << this->amount << endl;
            break;
        case 'd': //depositing gold
            cout << "Depositing gold." << endl;
            break;
	case 'x':
	    Person::show_status();
	    break;
    }
    
}
