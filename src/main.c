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

#include "../include/DataStructures/ascii.h"
#include "../include/DataStructures/bases.h"


int main(int argc, char * argv[])
{
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
        // score = launch_game();
        score = 0;
        printf("Score final: %d\n", score);
        // TODO: implémenter un classement?
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
