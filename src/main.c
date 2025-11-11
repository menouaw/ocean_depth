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

#include "../include/DataStructures/ascii.h"
#include "../include/DataStructures/bases.h"
#include "../include/Game/map.h"


int main(int argc, char * argv[])
{
    srand(time(NULL));

    int choice;
    int score;

    ascii_title();

    printf("S%clectionnez:\n", 130);
    printf("1. Lancer une partie.\n");
    printf("2. Quitter.\n");

    // scanf("%d", &choice);
    choice=1;

    switch (choice)
    {
    case 1:
        // ascii_new_game();
        printf("----------\n"
               "Nouvelle partie!\n");
        // initialisation des personnages (et de leurs caractéristiques)
        Player * player = malloc(sizeof(Player));
        player->map.nb_level = NB_LEVEL;
        player->map.room_by_level = NB_ROOM_BY_LEVEL;

        // allouer la carte
        allocate_map(&(player->map));

        // TODO: peupler la carte
        populate_map(&(player->map));

        print_map(&(player->map));
        // score = launch_game();
        score = 0;

        // TODO: implémenter un classement?
        printf("Score final: %d\n", score);

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
