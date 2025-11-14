//
// Created by menou on 11/11/2025.
//

#include "../DataStructures/bases.h"

#define WAIT_TIME 3

#ifndef CODE_INTERFACE_H
#define CODE_INTERFACE_H

int get_player_choice(void);

void print_player_interface(Player * player);

void clear_screen();

void print_fight_player_infos(Player * player);

void print_fight_monster_infos(Monster * monster);

#endif //CODE_INTERFACE_H