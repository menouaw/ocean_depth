//
// Created by menou on 11/11/2025.
//

/**
 *    ________                                ___     ________                 __  .__
 *    \_____  \   ____  ____ _____    ____   / _ \_/\ \______ \   ____ _______/  |_|  |__
 *     /   |   \_/ ___\/ __ \\__  \  /    \  \/ \___/  |    |  \_/ __ \\____ \   __\  |  \
 *    /    |    \  \__\  ___/ / __ \|   |  \           |    `   \  ___/|  |_> >  | |   Y  \
 *    \_______  /\___  >___  >____  /___|  /          /_______  /\___  >   __/|__| |___|  /
 *            \/     \/    \/     \/     \/                   \/     \/|__|             \/
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "../include/DataStructures/ascii.h"
#include "../include/DataStructures/bases.h"
#include "../include/Game/map.h"
#include "../include/Game/player.h"
#include "../include/Game/actions.h"
#include "../include/Game/interface.h"


int main(int argc, char * argv[])
{
    srand(time(NULL));

    int choice;
    int victory;

    ascii_title();
    sleep(WAIT_TIME);
    clear_screen();

    printf("S%clectionnez:\n", 130);
    printf("1. Lancer une partie.\n");
    printf("2. Quitter.\n");

    // scanf("%d", &choice);
    choice=1;

    switch (choice)
    {
    case 1:
        ascii_new_game();
        sleep(WAIT_TIME);
        clear_screen();

        // initialisation du joueur (et de ses caractéristiques)
        Player * player = malloc(sizeof(Player));
        player->score = 0;
        player->position.level = -1;
        player->position.room = -1;
        player->current_hp = NB_STARTING_HP;
        player->strength = NB_STARTING_STRENGTH;
        player->defense = NB_STARTING_DEFENSE;
        player->speed = NB_STARTING_SPEED;
        player->current_breathe = NB_STARTING_BREATHE;
        player->map.nb_level = NB_LEVEL;
        player->map.room_by_level = NB_ROOM_BY_LEVEL;
        player->exhaust = 0;
        player->money = 0;

        // allouer la carte
        allocate_map(&(player->map));

        // peupler la carte
        populate_map(&(player->map));

        print_map(&(player->map));
        victory = launch_game(player);

        // TODO: implémenter un classement?
        if (victory)
        {
            printf("Victoire!\n");
        } else
        {
            printf("D%cfaite...\n", 130);
        }
        printf("Score final: %d\n", player->score);

        // libération
        free_map(&(player->map));
        free(player);

        break;
    case 2:
        printf("Bye!\n");
        break;
    default:
        printf("Saisie incorrecte.\n");
        break;
    }

    exit(EXIT_SUCCESS);
}
