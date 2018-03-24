#include "Game_Object.h"
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Gold_Mine.h"
#include <iostream>
using namespace std;

Gold_Mine::Gold_Mine():Game_Object('G', 0)
{
	state = 'f'; //full of gold
	amount = 100; //amount of gold
	cout << "Gold_Mine default constructed." << endl;
}

Gold_Mine::Gold_Mine(int inputId, Cart_Point inputLoc): Game_Object('G', inputId, inputLoc)
{
	state = 'f';
	amount = 100;
	cout << "Gold_Mine constructed." << endl;
}

//destructor
Gold_Mine::~Gold_Mine()
{
	cout << "Gold_Mine destructed." << endl;
}
//if the mine is empty
bool Gold_Mine::is_empty()
{
	if (amount==0)
		return true;
	else
		return false;
}
//amount to dig, if enough, return the left value;if not enough, reurn 0;
double Gold_Mine::dig_gold(double amount_to_dig)
{
	if (this->amount >= amount_to_dig)
	{
		amount = amount - amount_to_dig;
		return amount_to_dig;
	}
	else
	{
		amount_to_dig = amount;
		amount = 0;
		return amount_to_dig;
	}

}

//update gold mine status
bool Gold_Mine::update()
{
	if (is_empty()&&(state!='e'))
    {
        state = 'e';
        display_code = 'g';
        cout << "Gold_Mine " << get_id() << " has been depleted." << endl;
        return true;
    }
    else
    {
        return false;
    }
}

//show gold mine status
void Gold_Mine::show_status()
{
	cout << "Gold Mine status: " << display_code << get_id() << " at location " << location << " Contains " << this->amount << "." << endl;
}
