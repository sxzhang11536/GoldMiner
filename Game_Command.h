#ifndef GAME_COMMAND_H
#define GAME_COMMAND_H

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

void do_move_command(Model& model);
void do_work_command(Model& model);
void do_stop_command(Model& model);
void do_go_command(Model& model);
void do_run_command(Model& model);
void do_quit_command(Model& model);
void do_list_command(Model& model);
void do_attack_command(Model& model);
void do_new_command(Model& model);
//void do_save_command(Model& model);
//void do_restore_command(Model& model);


#endif
