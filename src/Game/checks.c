//
// Created by menou on 11/11/2025.
//

#include "../../include/Game/checks.h"

int check_player_is_alive(Player* player)
{
    int is_alive;

    if (player->current_hp <= 0 || player->current_breathe <= 0)
    {
        is_alive = 0;
    } else
    {
        is_alive = 1;
    }

    return is_alive;
}

int check_monster_is_alive(Monster* monster)
{
    int is_alive;

    if (monster->current_hp <= 0)
    {
        is_alive = 0;
    } else
    {
        is_alive = 1;
    }

    return is_alive;
}
