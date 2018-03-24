#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Input_Handling.h"
#include "Model.h"
#include "Game_Object.h"
#include "Town_Hall.h"
#include "Gold_Mine.h"
#include "Person.h"
#include "Miner.h"
#include "Soldier.h"
#include "View.h"
#include "Game_Command.h"
#include <fstream>


using namespace std;

void do_move_command(Model& model)
{
    int ID;
    double x,y;
    cin >> ID >> x >> y;
    try {
        Person* person = model.get_Person_ptr(ID);
        person->start_moving(Cart_Point(x,y));
    }
    catch (int ex) {
        cout << "Invalid input: Person ID number "<< ex << "is out of range. "<<endl;
    }
}

void do_work_command(Model& model)
{
    int ID1,ID2,ID3;
    cin >> ID1 >>ID2 >>ID3;
    try{
        Person* person = model.get_Person_ptr(ID1);
        Gold_Mine* mine = model.get_Gold_Mine_ptr(ID2);
        Town_Hall* hall = model.get_Town_Hall_ptr(ID3);
        person->start_mining(mine, hall);
    }
    catch (int ex) {
        cout << "Invalid input: Person ID number "<<ex<< " is out of range"<< endl;
    }
    catch (float ex1) {
        cout << "Invalid input: Gold Mine id number " << ex1 << " is out of range. " << endl;
    }
    catch (double ex2) {
        cout << "Invalid input: Town Hall id number " << ex2 << " is out of range." << endl;
    }
}

void do_stop_command(Model& model)
{
    int ID;
    cin >> ID;
    try{
    Person* person = model.get_Person_ptr(ID);
    person->stop();
    }
    catch (int ex){
        cout << "Invalid input: Person id number " << ex << " is out of range. " << endl;
    }
}


void do_go_command(Model& model)
{
    cout << "Advancing one tick." << endl;
    model.update();
}

void do_run_command(Model& model)
{
    cout << "Advancing to next event." << endl;
    for (int i = 0; i < 5; i++)
    {
        if (model.update())
            return;
    }
    return;
    
}


void do_quit_command(Model& model)
{
    
    cout << "Terminating program." << endl;
    delete &model;
    return;
    
}

void do_list_command(Model& model)
{
    model.show_status();
}

void do_attack_command(Model& model)
{
    int ID1,ID2;
    cin >> ID1 >>ID2;
    try{
        Person* person1 = model.get_Person_ptr(ID1);
        Person* person2 = model.get_Person_ptr(ID2);
        person1->start_attack(person2);
    }
    catch (int ex){
        cout << "Invalid input: Person id number " << ex << " is out of range. " << endl;
    }
    
}

void do_new_command(Model& model)
{
    char type;
    int ID, X, Y;
    cin >> type >> ID >> X >> Y;
    model.handle_new_command(type, ID, X, Y);
}
/***
void do_save_command(Model& model)
{
    string filename;
    cin>>filename;
    if(filename.length()>99)
    {
        throw invalid_argument("Filename out of length. Maximum 99 characters.");
    }
    else
    {
        ofstream output(filename);
        model.save(output);
        output.close();
    }
}

void do_restore_command(Model& model)
{
    string filename;
    cin>>filename;
    ifstream input(filename);
    if (input.fail())
    {
        throw invalid_argument("File does not exist");
    }
    model.restore(input);
    input.close();
    
}
***/
