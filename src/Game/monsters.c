//
// Created by menou on 11/11/2025.
//

#include "../../include/Game/monsters.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "../../include/Game/checks.h"
#include "../../include/DataStructures/ascii.h"
#include "../../include/Game/interface.h"
#include "../../include/Game/player.h"

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

    // if (player->current_hp - player->exhaust > monster->speed)
    if (player->speed > monster->speed)
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
            ascii_player_turn();
            ascii_player();
            sleep(WAIT_TIME);
            clear_screen();

            player_attack_monster(player, monster);
            is_alive = check_monster_is_alive(monster);
            ++turn;

            if (is_alive == 0)
            {
                reset_monster_hp(monster);
                player->score += P_SCORE_GAINS_ON_SUCCESS;
                winner = PLAYER_WINS;
                break;
            }
        } else // tour du monstre
        {
            ascii_monster_turn();
            ascii_monster();
            sleep(WAIT_TIME);
            clear_screen();

            monster_attack_player(player, monster);
            is_alive = check_player_is_alive(player);
            ++turn;

            if (is_alive == 0)
            {
                winner = MONSTER_WINS;
                break;
            }
        }
    }
    return winner;
}

void player_attack_monster(Player * player, Monster * monster)
{
    /*
     * quatre possibilités:
     *      - succès            (50%)
     *      - succès critique   (20%)
     *      - échec             (20%)
     *      - échec critique    (10%)
     */

    int rand_value = rand() % 100;

    ascii_attack_result();

    if (rand_value > 100-PROB_PLAYER_CRITICAL_FAILURE)
    {
        ascii_critical_failure();
        sleep(WAIT_TIME);
        clear_screen();

        player->current_hp -= P_HP_LOOSES_ON_FAILURE;
        player->current_breathe -= P_BREATHE_LOOSES_ON_FAILURE;
        player->exhaust += P_EXHAUST_GAINS_ON_FAILURE;


    } else if (rand_value > 100-PROB_PLAYER_FAILURE-PROB_PLAYER_CRITICAL_FAILURE)
    {
        ascii_failure();
        sleep(WAIT_TIME);
        clear_screen();

        player->exhaust += P_EXHAUST_GAINS_ON_FAILURE;
    } else if (rand_value > 100-PROB_PLAYER_CRITICAL_SUCCESS-PROB_PLAYER_FAILURE-PROB_PLAYER_CRITICAL_FAILURE)
    {
        ascii_critical_success();
        sleep(WAIT_TIME);
        clear_screen();

        // effets joueur
        player->strength += P_STRENGTH_GAINS_ON_SUCCESS;
        player->max_hp += P_HP_GAINS_ON_SUCCESS;
        player->speed += P_SPEED_GAINS_ON_SUCCESS;
        player->score += P_SCORE_GAINS_ON_SUCCESS * 2;

        // effets monstre
        monster->current_hp -= (monster->defense > player->strength*2)? MIN_VALUE_ATTACK : player->strength*2-monster->defense;

    } else if (rand_value > 100-PROB_PLAYER_SUCCESS-PROB_PLAYER_CRITICAL_SUCCESS-PROB_PLAYER_CRITICAL_FAILURE-PROB_PLAYER_FAILURE)
    {
        ascii_success();
        sleep(WAIT_TIME);
        clear_screen();

        player->strength += P_STRENGTH_GAINS_ON_SUCCESS;
        player->score += P_SCORE_GAINS_ON_SUCCESS;
        player->exhaust += P_EXHAUST_GAINS_ON_SUCCESS;

        monster->current_hp -= (monster->defense > player->strength)? MIN_VALUE_ATTACK : player->strength-monster->defense;
    } else
    {
        fprintf(stderr, "Erreur sur l'attaque du joueur.\n");
    }

    player->current_breathe -= P_BREATHE_LOOSES_ON_ATTACK;
}

void monster_attack_player(Player * player, Monster * monster)
{
    int rand_value = rand() % 100;
    int monster_attack = monster->min_strength + rand() % (monster->max_strength - monster->min_strength + 1);

    ascii_attack_result();

    if (rand_value > 100-PROB_MONSTER_CRITICAL_FAILURE)
    {
        ascii_critical_failure();
        sleep(WAIT_TIME);
        clear_screen();

        monster->current_hp -= M_HP_LOOSES_ON_FAILURE*2;
        monster->defense -= M_DEFENSE_LOOSES_ON_FAILURE;
    } else if (rand_value > 100-PROB_MONSTER_CRITICAL_SUCCESS-PROB_MONSTER_CRITICAL_FAILURE)
    {
        ascii_critical_success();
        sleep(WAIT_TIME);
        clear_screen();

        // effets monstre
        monster->current_hp += M_HP_GAINS_ON_SUCCESS;
        monster->defense += M_DEFENSE_GAINS_ON_SUCCESS;

        // effets joueur
        player->current_hp -= (player->defense > monster_attack)? MIN_VALUE_ATTACK : player->defense - monster_attack;
    } else if (rand_value > 100-PROB_MONSTER_FAILURE-PROB_MONSTER_CRITICAL_SUCCESS-PROB_MONSTER_CRITICAL_FAILURE)
    {
        ascii_failure();
        sleep(WAIT_TIME);
        clear_screen();

        monster->defense -= M_DEFENSE_LOOSES_ON_FAILURE;
    } else if (rand_value > 100-PROB_MONSTER_SUCCESS-PROB_MONSTER_FAILURE-PROB_MONSTER_CRITICAL_SUCCESS-PROB_MONSTER_CRITICAL_FAILURE)
    {
        ascii_success();
        sleep(WAIT_TIME);
        clear_screen();

        player->current_hp -= (player->defense > monster_attack)? MIN_VALUE_ATTACK : player->defense - monster_attack;
    } else
    {
        fprintf(stderr, "Erreur sur l'attaque du monstre.\n");
    }
}

void reset_monster_hp(Monster * monster)
{
    monster->current_hp = monster->max_hp;
}


Monster jellyfish = {
    .id=0,
    .name = "Meduse",
    .max_hp = 20,
    .current_hp = 20,
    .min_strength = 5,
    .max_strength = 10,
    .defense = 2 ,
    .speed = 2,
    .special_power = "Electrocution",
};

Monster shark = {
    .id=1,
    .name = "Requin",
    .max_hp = 30,
    .current_hp = 30,
    .min_strength = 10,
    .max_strength = 20,
    .defense = 5,
    .speed = 5,
    .special_power = "Morsure"
};