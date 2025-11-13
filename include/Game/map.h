//
// Created by menou on 11/11/2025.
//

#include "../DataStructures/bases.h"

#define NB_LEVEL            30
#define NB_ROOM_BY_LEVEL    30

#define PROB_MONSTER        50
#define PROB_TREASURE       25
#define PROB_EVENT          15
#define PROB_EMPTY_ROOM     10

#ifndef CODE_MAP_H
#define CODE_MAP_H

void allocate_map(Map * map);

void populate_map(Map * map);

void print_map(Map * map);

void free_map(Map * map);

#endif //CODE_MAP_H