#include "Game_Object.h"
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include <iostream>
using namespace std;

Game_Object::Game_Object()
{
    cout<<"Game_Object default constructed."<<endl;
}

Game_Object::Game_Object(char in_code, int in_id)
{
	display_code = in_code; //initializes the display_code
	id_num = in_id; //initialize the id_num
	location = Cart_Point(0, 0); //initialize the location
	cout << "Game_Object default constructed." << endl; //outputs the message
}

Game_Object::Game_Object(char in_code, int in_id, Cart_Point in_loc)
{
	display_code = in_code; //intializes the display_code
	id_num = in_id; //initialize the id_num
	location = in_loc; //initialize the location
	cout << "Game_Object constructed." << endl; //outputs the message
}

Game_Object::~Game_Object()  //destructor
{
    cout<<"Game_Object destructed."<<endl;
}

Cart_Point Game_Object::get_location()
{
	return location;
}

int Game_Object::get_id()
{
	return id_num;
}

void Game_Object::show_status()
{
	cout << display_code << " with ID " << id_num << " at location " << location << endl;
}

void Game_Object::drawself(char* ptr)
{
    *ptr = this->display_code;
    *(ptr+1) = '0' + this->get_id();
    
}

bool Game_Object::is_alive()
{
    return true;
}
