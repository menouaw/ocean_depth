//
// Created by menou on 11/11/2025.
//

#include "../../include/Game/monsters.h"

#include <stdlib.h>

#include "../../include/Game/checks.h"

const Monster * monsters[] = {
    &jellyfish,
    &shark,
};

Monster generate_monster()
{
    return * monsters[rand() % NB_MONSTERS];
}

int fight_monster(Player * player, Monster * monster)
{
    int winner = FIGHT_IN_PROGRESS;
    int is_alive = -1;
    int turn;

    if (player->current_hp - player->exhaust > monster->speed)
    {
        turn = 0; // joueur commence
    } else
    {
        turn = 1; // monstre commence
    }

    while (winner == FIGHT_IN_PROGRESS)
    {
        if (turn%2==0) // tour du joueur
        {
            player_attack_monster(player, monster);
            is_alive = check_monster_hp(monster);
            ++turn;

            if (is_alive == 0)
            {
                reset_monster_hp(monster);
                winner = PLAYER_WINS;
                break;
            }
        } else
        {
            monster_attack_player(player, monster);
            is_alive = check_player_hp(player);
            ++turn;

            if (is_alive == 0)
            {
                winner = MONSTER_WINS;
                break;
            }
        }

        return winner;
    }
}

int player_attack_monster(Player * player, Monster * monster)
{
}

int monster_attack_player(Player * player, Monster * monster)
{
}

void reset_monster_hp(Monster * monster)
{
    monster->current_hp = monster->max_hp;
}


const Monster jellyfish = {
    .id=0,
    .name = "Meduse",
    .max_hp = 20,
    // .current_hp = .max_hp,
    .min_strength = 5,
    .max_strength = 10,
    .defense = 2,
    .speed = 2,
    .special_power = "Electrocution"
};

const Monster shark = {
    .id=1,
    .name = "Requin",
    .max_hp = 30,
    // .current_hp = .max_hp,
    .min_strength = 10,
    .max_strength = 20,
    .defense = 5,
    .speed = 5,
    .special_power = "Morsure"
};