#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Game_Object.h"

using namespace std;

const int view_maxsize = 20;

class View
{
private:
    int size;
    double scale;
    Cart_Point origin;
    char grid[view_maxsize][view_maxsize][2];
    bool get_subscripts(int&, int&, Cart_Point);
    
public:
    View();
    ~View();
    
    void clear();
    void plot(Game_Object* ptr);
    void draw();
};

#endif

