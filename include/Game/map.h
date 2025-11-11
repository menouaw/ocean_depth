//
// Created by menou on 11/11/2025.
//

#include "../DataStructures/bases.h"

#define NB_LEVEL 3
#define NB_ROOM_BY_LEVEL 3

#ifndef CODE_MAP_H
#define CODE_MAP_H

void allocate_map(Map * map);

void print_map(Map * map);

void free_map(Map * map);

#endif //CODE_MAP_H