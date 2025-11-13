//
// Created by menou on 11/11/2025.
//

#include "../../include/Game/actions.h"
#include "../../include/DataStructures/ascii.h"

#include <stdio.h>
#include <unistd.h>

#include "../../include/Game/checks.h"
#include "../../include/Game/interface.h"
#include "../../include/Game/events.h"
#include "../../include/Game/map.h"
#include "../../include/Game/monsters.h"
#include "../../include/Game/treasure.h"

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

    int victory = GAME_IN_PROGRESS;
    int room_result;
    int choice;

    while (victory == GAME_IN_PROGRESS)
    {
        print_player_interface(player);
        choice = get_player_choice();

        move_to_room(player, player->position.level+1, choice);
        // printf("Level: %d,\n Room: %d\n", player->position.level, player->position.room);

        room_result = consume_room(player);

        if (room_result == MONSTER_WINS)
        {
            victory = GAME_LOOSE;
        }

        if (player->position.level == NB_LEVEL-1)
        {
            victory = GAME_WIN;
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
    int room_result = FIGHT_IN_PROGRESS;

    if (player->map.map[player->position.level][player->position.room] == 'M')
    {
        ascii_fight();
        sleep(WAIT_TIME);
        clear_screen();
        Monster monster = generate_monster();
        room_result = fight_monster(player, &monster);

    } else if (player->map.map[player->position.level][player->position.room] == 'T')
    {
        ascii_treasure();
        sleep(WAIT_TIME);
        clear_screen();
        open_chest(player);
    } else if (player->map.map[player->position.level][player->position.room] == 'E')
    {
        tornado(player);
    } else if (player->map.map[player->position.level][player->position.room] == 'V')
    {
        // salle vide: rien à faire
        // ascii_empty_room();
        // sleep(WAIT_TIME);
        // clear_screen();
    } else if (player->map.map[player->position.level][player->position.room] == 'B')
    {
        // TODO: implémenter un combat de boss
        // ascii_boss();
        // sleep(WAIT_TIME);
        // clear_screen();
    } else
    {
        if (player->position.level != 0) // FIX??
        {
            fprintf(stderr, "Erreur lors de la consommation de la salle.\n");
        }
    }

    player->current_breathe -= P_BREATHE_LOOSES_BY_ROOM;

    if (check_player_is_alive(player) == 0)
    {
        room_result = MONSTER_WINS;
    }

    return room_result;
}
