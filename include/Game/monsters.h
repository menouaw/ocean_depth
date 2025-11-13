//
// Created by menou on 11/11/2025.
//

#include "../DataStructures/bases.h"

#define NB_MONSTERS 2

#define FIGHT_IN_PROGRESS   -1
#define PLAYER_WINS         1
#define MONSTER_WINS        0

#define MIN_VALUE_ATTACK 1

#define PROB_MONSTER_SUCCESS             40
#define PROB_MONSTER_CRITICAL_SUCCESS    15
#define PROB_MONSTER_FAILURE             35
#define PROB_MONSTER_CRITICAL_FAILURE    10

#define M_HP_GAINS_ON_SUCCESS           2
#define M_HP_LOOSES_ON_FAILURE          5
#define M_DEFENSE_GAINS_ON_SUCCESS      2
#define M_DEFENSE_LOOSES_ON_FAILURE     5

#ifndef CODE_MONSTERS_H
#define CODE_MONSTERS_H

extern Monster jellyfish;
extern Monster shark;

Monster generate_monster();

int fight_monster(Player * player, Monster * monster);

void player_attack_monster(Player * player, Monster * monster);

void monster_attack_player(Player * player, Monster * monster);

void reset_monster_hp(Monster * monster);

#endif //CODE_MONSTERS_H