//
// Created by menou on 13/11/2025.
//

#include "../../include/Game/events.h"

#include <stdlib.h>

#include "../../include/Game/player.h"
#include "../../include/Game/actions.h"

void tornado_event(Player* player)
{
    move_to_room(player, rand() % (NB_LEVEL-1), rand() % (NB_ROOM_BY_LEVEL));

    player->current_breathe -= P_BREATHE_LOOSES_ON_TORNADO;
    player->exhaust += P_EXHAUST_GAINS_ON_TORNADO;
}
