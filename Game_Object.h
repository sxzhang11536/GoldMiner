#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <iostream>
#include "Cart_Point.h"
#include "Cart_Vector.h"
using namespace std;

class Game_Object
{
private:
	int id_num;
    //double amount;
    
protected:
	Cart_Point location;
	char display_code;
	char state;
public:
    Game_Object();
	Game_Object(char, int);
	Game_Object(char, int, Cart_Point);
    virtual ~Game_Object();
	
    Cart_Point get_location();
	int get_id();
	virtual void show_status();
    virtual bool update()=0;
    void drawself(char* ptr);
    virtual bool is_alive();
};

#endif
