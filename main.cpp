#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Game_Object.h"
#include "Gold_Mine.h"
#include "Town_Hall.h"
#include "Person.h"
#include "Miner.h"
#include "Model.h"
#include "Game_Command.h"
#include "View.h"
#include "Input_Handling.h"
#include <iostream>
using namespace std;

int main()
{
    char command;
    cout << "EC327: Programming Assignment 4 -- Fall 2016" << endl;
    
    Model* model = new Model();
    View* view = new View();
    view->clear();
    do_list_command(*model);
    
    do
    {
    model->display(*view);
    cout << "Enter command: ";
    cin >> command;
    try{
            if (command == 's')
            {
                //view.clear();
                do_stop_command(*model);
            }
            else if (command == 'm')
            {
                //view.clear();
                do_move_command(*model);
            }
            else if (command == 'w')
            {
                //view.clear();
                do_work_command(*model);
            }
            else if (command == 'g')
            {
                //view.clear();
                do_go_command(*model);
                do_list_command(*model);
            }
            else if (command == 'r')
            {
                //view.clear();
                do_run_command(*model);
                do_list_command(*model);
            }
            else if (command == 'a')
            {
                do_attack_command(*model);
                do_list_command(*model);
            }
            else if (command == 'n')
            {
                do_new_command(*model);
            }
            else if (command =='q')
            {
                do_quit_command(*model);
            }
            else
            {
                throw Invalid_Input("This command code is not found.");
            }
    }
        catch (Invalid_Input& except)
        {
            cout << "Invalid input -  "<< except.msg_ptr << endl;
        }
    }while (command != 'q');
    return 0;
    
}

