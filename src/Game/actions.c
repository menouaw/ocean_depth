//
// Created by menou on 11/11/2025.
//

#include "../../include/Game/actions.h"

#include <stdio.h>

#include "../../include/Game/interface.h"
#include "../../include/Game/map.h"

int launch_game(Player * player)
{
    /*
     * 1. afficher l'état actuel (caractéristiques, position, etc.)
     * 2. inviter à choisir une action (descendre d'une salle, utiliser un équipement, etc.)
     * 3. effectuer l'action choisie
     * 4. vérifier la victoire/défaite
     * 5a. si victoire (1) ou défaite (0), arrêter la boucle et retourner le score
     * 5b. retourner à l'étape 1
     */

    int victory = -1;
    int choice;

    while (victory == -1)
    {
        print_player_interface(player);
        choice = get_player_choice();

        move_to_room(player, player->position.level+1, choice);
        // printf("Level: %d,\n Room: %d\n", player->position.level, player->position.room);

        consume_room(player);

        if (player->position.level == NB_LEVEL-1)
        {
            victory = 1;
        }
    }
    return victory;
}

char move_to_room(Player * player, int level, int room)
{
    player->position.level = level;
    player->position.room = room;


    return player->map.map[level][room];
}

/*
*      - 50% de monstres           (M)
*      - 25% de trésors            (T)
*      - 15% d'évènements spéciaux (E)
*      - 10% de salles vides       (V)
*      + si dernier niveau: boss   (B)
*/
int consume_room(Player * player)
{
    int is_alive;

    if (player->map.map[player->position.level][player->position.room] == 'M')
    {

    } else if (player->map.map[player->position.level][player->position.room] == 'T')
    {

    } else if (player->map.map[player->position.level][player->position.room] == 'E')
    {

    } else if (player->map.map[player->position.level][player->position.room] == 'V')
    {

    } else if (player->map.map[player->position.level][player->position.room] == 'B')
    {

    } else
    {
        is_alive = 1;
    }

    return is_alive;
}
