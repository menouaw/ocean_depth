//
// Created by menou on 11/11/2025.
//

#include "../../include/Game/interface.h"

#include <stdio.h>
#include <stdlib.h>

#include "../../include/Game/map.h"

int get_player_choice(void)
{
    int choice = -1;
    do
    {
        printf("Choisissez une salle en aval (doit %ctre comprise entre 0 et %d): ", 136, NB_ROOM_BY_LEVEL-1);
        scanf("%d", &choice);

        if (choice >= NB_ROOM_BY_LEVEL || choice < 0)
        {
            printf("Saisie incorrecte.\n");
            while (getchar() != '\n');
            choice = -1;
        }
    } while (choice == -1);

    return choice;
}

void print_player_interface(Player* player)
{
    printf("R%ccapitulatif: \n"
           "Profondeur: %d.\n"
           "Salle: %d.\n"
           "Score: %d.\n"
           "Points de vie actuels: %d.\n"
           "Souffle restant: %d.\n"
           "Fatigue: %d.\n"
           "Bourse: %d.\n", 130, player->position.level+1, player->position.room, player->score, player->current_hp,
           player->current_breathe, player->exhaust, player->money);
}

void clear_screen()
{
    system("cls");
}