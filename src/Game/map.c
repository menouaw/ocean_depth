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

void print_map(Map* map)
{
    for (int i = 0; i < map->nb_level; ++i)
    {
        printf("Niveau: -%d | ", i);
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
