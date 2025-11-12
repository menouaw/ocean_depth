//
// Created by menou on 11/11/2025.
//

#include "../../include/Game/map.h"

#include <stdio.h>
#include <stdlib.h>

void allocate_map(Map* map)
{
    map->map = malloc(sizeof(char *) * map->nb_level);

    for (int i = 0; i < map->nb_level; ++i)
    {
        map->map[i] = malloc(sizeof(char) * map->room_by_level);

        for (int j = 0; j < map->room_by_level; ++j)
        {
            map->map[i][j] = '~';
        }
    }
}

void populate_map(Map * map)
{
    /*
     * 1. parcourir chaque salle, de chaque niveau
     * 2. placer, par niveau:
     *      - 50% de monstres           (M)
     *      - 25% de trésors            (T)
     *      - 15% d'évènements spéciaux (E)
     *      - 10% de salles vides       (V)
     *      + si dernier niveau: boss   (B)
     */

    // FIX: il y aura un souci si on change l'ordre de proba des salles

    int rand_value;

    for (int i = 0; i < map->nb_level; ++i)
    {
        for (int j = 0; j < map->room_by_level; ++j)
        {
            rand_value = rand() % 100;
            if (rand_value > 100-PROB_EMPTY_ROOM)
            {
                map->map[i][j] = 'V';
            } else if (rand_value > 100-PROB_EVENT-PROB_EMPTY_ROOM)
            {
                map->map[i][j] = 'E';
            } else if (rand_value > 100-PROB_TREASURE-PROB_EVENT-PROB_EMPTY_ROOM)
            {
                map->map[i][j] = 'T';
            } else if (rand_value > 100-PROB_MONSTER-PROB_TREASURE-PROB_EVENT-PROB_EMPTY_ROOM)
            {
                map->map[i][j] = 'M';
            } else
            {
                fprintf(stderr, "Erreur sur l'assignation de la salle.\n");
            }

            // boss légendaire en cas d'atteinte du dernier niveau
            if (i == map->nb_level-1)
            {
                map->map[i][j] = 'B';
            }
        }
    }
}

void print_map(Map* map)
{
    for (int i = 0; i < map->nb_level; ++i)
    {
        printf("Niveau: -%d | ", i+1);
        for (int j = 0; j < map->room_by_level; ++j)
        {
            printf("%3c", map->map[i][j]);
        }
        printf("\n");
    }
}

void free_map(Map* map)
{
    for (int i = 0; i < map->nb_level; ++i)
    {
        free(map->map[i]);
    }
    free(map->map);
}
