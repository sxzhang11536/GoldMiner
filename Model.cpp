#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Game_Object.h"
#include "Gold_Mine.h"
#include "Town_Hall.h"
#include "Person.h"
#include "Miner.h"
#include "Model.h"
#include "View.h"
#include <iostream>
#include <ctime>

using namespace std;

Model::Model()
{
    time = 0;

    
    //Gold_Mine* Gold_Mine1 = new Gold_Mine(1, Cart_Point(1,20));
    //Object pointer setup
    //object_ptrs = new Game_Object*[num_objects];
    
    //Miner 1
    //person_ptrs = new Miner*[num_persons];
    Miner* Miner1 = new Miner(1, Cart_Point(5, 1));
    object_ptrs.push_back(Miner1);
    active_ptrs.push_back(Miner1);
    person_ptrs.push_back(Miner1);

    //Miner 2
    Miner* Miner2 = new Miner(2, Cart_Point(10, 1));
    object_ptrs.push_back(Miner2);
    active_ptrs.push_back(Miner2);
    person_ptrs.push_back(Miner2);
    
    //soldier1
    Soldier* Soldier1=new Soldier(3,Cart_Point(5, 15));
    object_ptrs.push_back(Soldier1);
    active_ptrs.push_back(Soldier1);
    person_ptrs.push_back(Soldier1);
    
    
    //soldier2
    Soldier* Soldier2 = new Soldier(4, Cart_Point(10, 15));
    object_ptrs.push_back(Soldier2);
    active_ptrs.push_back(Soldier2);
    person_ptrs.push_back(Soldier2);

    
    //Mine1
    //mine_ptrs = new Gold_Mine*[num_mines];
    Gold_Mine* Gold_Mine1 = new Gold_Mine(1, Cart_Point(1, 20));
    object_ptrs.push_back(Gold_Mine1);
    active_ptrs.push_back(Gold_Mine1);
    mine_ptrs.push_back(Gold_Mine1);

    
    //Mine2
    Gold_Mine* Gold_Mine2 = new Gold_Mine(2, Cart_Point(10, 20));
    object_ptrs.push_back(Gold_Mine2);
    active_ptrs.push_back(Gold_Mine2);
    mine_ptrs.push_back(Gold_Mine2);

    
    //TownHall0
    //hall_ptrs = new Town_Hall*[num_halls];
    Town_Hall* Town_Hall0 = new Town_Hall();
    object_ptrs.push_back(Town_Hall0);
    active_ptrs.push_back(Town_Hall0);
    hall_ptrs.push_back(Town_Hall0);
    

    
    cout << "Model default constructed." << endl; //the handout says "default" but the sample output is different
    
}

Model::~Model()
{
    
    list<Game_Object*>::iterator i;
    for (i = object_ptrs.begin(); i != object_ptrs.end(); i++)
    {
        delete *i;
    }
    
    cout << "Model destructed." << endl;
}

Person* Model::get_Person_ptr(int id)
{

    list<Person*>::iterator i;
    for (i = person_ptrs.begin(); i != person_ptrs.end(); i++)
    {
        Person* person_ptr = *i;
        if (person_ptr->get_id() == id)
        {
            return person_ptr;
        }
    }
    return 0;
}


Gold_Mine* Model::get_Gold_Mine_ptr(int id)
{

    list<Gold_Mine*>::iterator i;
    for (i = mine_ptrs.begin(); i != mine_ptrs.end(); i++)
    {
        Gold_Mine* mine_ptr = *i;
        if (mine_ptr->get_id() == id)
        {
            return mine_ptr;
        }
    }
    return 0;
}

Town_Hall* Model::get_Town_Hall_ptr(int id)
{
    list<Town_Hall*>::iterator i;
    for (i = hall_ptrs.begin(); i != hall_ptrs.end(); i++)
    {
        Town_Hall* hall_ptr = *i;
        if (hall_ptr->get_id() == id)
        {
            return hall_ptr;
        }
    }
    return 0;
}

bool Model::update()
{
    time++;
    bool foo = false;
    list<Game_Object*>::iterator i;
    for (i = object_ptrs.begin(); i != object_ptrs.end(); i++)
    {
        Game_Object* game_ptr = *i;
        if (game_ptr->update())
        {
            foo=true;
        }
        if (game_ptr->is_alive()==false)
        {
            active_ptrs.remove(game_ptr);
        }
    }
    return foo;
}

void Model::display(View& view)
{
    
    view.clear();
    list<Game_Object*>::iterator i;
    for (i = active_ptrs.begin(); i != active_ptrs.end(); i++)
    {
        view.plot(*i);
        
    }
    view.draw();
    //view.clear();
}

void Model::show_status()
{
    cout << "Time: " << time << endl;
    list<Game_Object*> :: iterator i;
    for (i = object_ptrs.begin(); i != object_ptrs.end(); i++)
    {
        Game_Object* game_ptr=*i;
        game_ptr->show_status();
    }
}


void Model::handle_new_command(char type,int ID,double X,double Y)
{
    switch (type)
    {
    case 'g':
        {
            bool valid_mine = true;
            list<Gold_Mine*>::iterator i;
            for (i = mine_ptrs.begin(); i !=mine_ptrs.end();i++)
            {
                Gold_Mine* goldmine_ptr = *i;
                if (goldmine_ptr->get_id()== ID)
                {
                    valid_mine=false;
                }
            }
            if (valid_mine == true)
            {
                Gold_Mine* newgoldmine = new Gold_Mine(ID,Cart_Point(X,Y));
                object_ptrs.push_back(newgoldmine);
                active_ptrs.push_back(newgoldmine);
                mine_ptrs.push_back(newgoldmine);
            }
            else
            {
                cout << "ID number already exists!" << endl;
            }
            
        }break;
    case 't':
        {
            bool valid_town = true;
            list <Town_Hall*>::iterator i;
            for (i = hall_ptrs.begin();i != hall_ptrs.end();i++)
            {
                Town_Hall* hall_ptr = *i;
                if (hall_ptr->get_id()==ID)
                {
                    valid_town = false;
                }
            }
            if (valid_town==true)
            {
                Town_Hall* newtownhall = new Town_Hall(ID, Cart_Point(X, Y));
                object_ptrs.push_back(newtownhall);
                active_ptrs.push_back(newtownhall);
                hall_ptrs.push_back(newtownhall);
            }
            else
            {
                cout << "ID number already exists!" << endl;
            }
        }break;
    case 'm':
        {
            bool valid_miner = true;
            list <Person*>::iterator i;
            for (i = person_ptrs.begin();i != person_ptrs.end();i++)
            {
                Person* person_ptr = *i;
                if (person_ptr->get_id()==ID)
                {
                    valid_miner = false;
                }
            }
            if (valid_miner==true)
            {
                Miner* newminer = new Miner(ID, Cart_Point(X, Y));
                object_ptrs.push_back(newminer);
                active_ptrs.push_back(newminer);
                person_ptrs.push_back(newminer);
            }
            else
            {
                cout << "ID number already exists!" << endl;
            }
        }break;
            
    case 's':
        {
            bool valid_soldier = true;
            list <Person*>::iterator i;
            for (i = person_ptrs.begin();i != person_ptrs.end();i++)
            {
                Person* person_ptr = *i;
                if (person_ptr->get_id()==ID)
                {
                    valid_soldier=false;
                }
            }
            if (valid_soldier==true)
            {
                Soldier* newsoldier = new Soldier(ID, Cart_Point(X, Y));
                object_ptrs.push_back(newsoldier);
                active_ptrs.push_back(newsoldier);
                person_ptrs.push_back(newsoldier);
            }
            else
            {
                cout << "ID number already exists!" << endl;
            }
        }break;
            
    }
}
/***
void Model::save(ofstream& file)
{
    file<<time<<endl;
    file<<active_ptrs.size()<<endl;
    list<GameObject*>::iterator i;
    for(i=active_ptrs.begin(); i != active_ptrs.end(); ++i)
    {
        GameObject* temp=*i;
        file<<temp->get_code()<<" ";
        file<<temp->get_id()<<endl;
    }
    list<GameObject*>::iterator j;
    for(j=active_ptrs.begin(); j!= active_ptrs.end(); ++j)
    {
        GameObject* temp1=*j;
        temp1->save(file);
    }
    
}

void Model::restore(ifstream& file)
{
    
    Model::~Model();
    file>>time;
    int activesize;
    file>>activesize;
    char code;
    int id;
    for (int i=0; i<activesize; i++)
    {
        file>>code;
        file>>id;
        if (code=='T')
        {
            Tuna* t1 = new Tuna(id,this);
            setnewtuna(t1);
            //  t1->restore(file, *this);
        }
        else if (code=='s')
        {
            Shark* s1= new Shark(id);
            setnewshark(s1);
            //    s1->restore(file, *this);
        }
        else if (code=='c')
        {
            Cave* c1 = new Cave (id);
            setnewcave(c1);
            //  c1->restore(file, *this);
        }
        else if (code=='R')
        {
            CoralReef* r1=new CoralReef(id);
            setnewreef(r1);
            //r1->restore(file, *this);
        }
    }
    list<GameObject*>::iterator j;
    for(j=active_ptrs.begin(); j!= active_ptrs.end(); ++j)
    {
        GameObject* temp=*j;
        temp->restore(file, *this);
    }
    Model::show_status();
    
}
***/
















