#include <iostream>
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Game_Object.h"
#include "Town_Hall.h"
using namespace std;
//default constructor
Town_Hall::Town_Hall():Game_Object('t', 1)
{
    state = 'o'; //original level
    amount = 0;
    cout << "Town_Hall default constructed." << endl;
}

Town_Hall::Town_Hall(int inputId, Cart_Point inputLoc): Game_Object('t', inputId, inputLoc)
{
    state = 'o';
    amount = 0;
    cout << "Town_Hall constructed." << endl;
}
//destructor
Town_Hall::~Town_Hall()
{
    cout << "Town_Hall destructed." << endl;
}
//new amount = amount plus the deposit amount
void Town_Hall::deposit_gold(double deposit_amount)
{
    amount = amount + deposit_amount;
}
//if greater than 50 and has not been updated, return true.
bool Town_Hall::update()
{
    if ((amount >= 50)&&(state!='u'))
    {
        state = 'u';
        display_code = 'T';
        //cout << display_code << get_id() << " Upgraded." << endl;
        return true;
    }
    else
    {
        return false;
    }
}

void Town_Hall::show_status()
{
    cout << "Town Hall status: " << display_code << get_id() <<  " at " << location << " contains " << amount << " of gold.";
    //bool loo = update();
    if (display_code=='T')
    {
        cout << " Upgraded." << endl;
    }
    else
    {
        cout << " Not yet upgraded." << endl;
    }
}
