//
// Created by menou on 12/11/2025.
//

#include "../../include/Game/treasure.h"

#include <stdlib.h>
#include <unistd.h>

#include "../../include/Game/player.h"

void open_chest(Player* player)
{
    player->money += MIN_MONEY_IN_CHEST + (rand() % MAX_MONEY_IN_CHEST + 1);
    player->score += P_SCORE_GAINS_ON_CHEST;
}
