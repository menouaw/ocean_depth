//
// Created by menou on 11/11/2025.
//

#include "../DataStructures/bases.h"

#define NB_MONSTERS 2

#define FIGHT_IN_PROGRESS -1
#define PLAYER_WINS 1
#define MONSTER_WINS 0

#ifndef CODE_MONSTERS_H
#define CODE_MONSTERS_H

extern Monster jellyfish;
extern Monster shark;

Monster generate_monster();

int fight_monster(Player * player, Monster * monster);

int player_attack_monster(Player * player, Monster * monster);

int monster_attack_player(Player * player, Monster * monster);

void reset_monster_hp(Monster * monster);

#endif //CODE_MONSTERS_H