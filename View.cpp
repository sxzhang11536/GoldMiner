#include "View.h"
#include <iostream>
//default
View::View()
{
    size = 11;
    scale = 2;
    origin = Cart_Point(0,0);
}
//destructor
View::~View()
{
    cout << "View destructed." << endl;
}

bool View::get_subscripts(int &ix, int &iy, Cart_Point location)
{
    ix = (location.x - origin.x)/(scale);
    iy = (location.y - origin.y)/(scale);
    if (ix <= size && iy <= size && ix >= 0 && iy >= 0)
    {
        return true;
    }
    else
    {
        cout<<"An object is outside the display"<<endl;
        return false;
    }
}

//sets all the cells of the grid to the background pattern
void View::clear()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            grid[i][j][0] = '.';
            grid[i][j][1] = ' ';
        }
    }
}

//plot game object
void View::plot(Game_Object *ptr)
{
    int ix,iy;
    if (get_subscripts(ix, iy, ptr->get_location()))
    {
        if (grid[iy][ix][0] == '.')
        {
            ptr->drawself(grid[iy][ix]);
        }
        else
        {
            grid[iy][ix][0] = '*';
            grid[iy][ix][1] = ' ';
        }
    }
}


void View::draw()
{
    int coordinate = int(size * scale);
    for (int i = 10; i >= 0; i--)
    {
        coordinate = coordinate - scale;
        if (coordinate >= 10 && (coordinate == 12 || coordinate == 16 || coordinate == 20))
        {
            cout << coordinate;
        }
        else if (coordinate == 2 || coordinate == 6 || coordinate == 10 || coordinate == 14 || coordinate == 18)
        {
            cout << "  ";
        }
        else if (coordinate <= 10 && (coordinate == 0 || coordinate == 4 || coordinate == 8))
        {
            cout << coordinate << " ";
        }
        for (int j = 0; j < size; j++)
        {
            cout << grid[i][j][0] << grid[i][j][1];
        }
        cout << endl;
    }
    
    cout << "  0   4   8   12  16  20" << endl;
}
