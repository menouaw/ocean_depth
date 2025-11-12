//
// Created by menou on 12/11/2025.
//

#include "../../include/Game/treasure.h"

#include <stdlib.h>
#include <unistd.h>

#include "../../include/DataStructures/ascii.h"

void open_chest(Player* player)
{
    ascii_chest();
    sleep(WAIT_TIME);
    clear_screen();
    player->money += MIN_MONEY_IN_CHEST + (rand() % MAX_MONEY_IN_CHEST + 1);
}
