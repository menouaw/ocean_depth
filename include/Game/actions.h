//
// Created by menou on 11/11/2025.
//

#include "../DataStructures/bases.h"

#define GAME_IN_PROGRESS    -1
#define GAME_WIN            1
#define GAME_LOOSE          0

#define P_BREATHE_LOOSES_BY_ROOM 10

#ifndef CODE_ACTIONS_H
#define CODE_ACTIONS_H

int launch_game(Player * player);

char move_to_room(Player * player, int level, int room);

int consume_room(Player * player);

#endif //CODE_ACTIONS_H