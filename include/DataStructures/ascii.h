//
// Created by menou on 11/11/2025.
//

#ifndef CODE_ASCII_H
#define CODE_ASCII_H

extern const char * new_game_modular;

extern const char * title_bulbhead;

extern const char * title_crawford_2;

extern const char * title_modular;

extern const char * fight;

extern const char * treasure;

extern const char * chest;

extern const char * monster;

extern const char * success;

extern const char * critical_success;

extern const char * failure;

extern const char * critical_failure;

extern const char * player;

extern const char * player_turn;

extern const char * monster_turn;

extern const char * attack_result_frame_one;

extern const char * attack_result_frame_two;

extern const char * attack_result_frame_three;

extern const char * end_boss;

void ascii_end_boss();

extern const char * empty;

extern const char * empty_room;

void ascii_empty_room();

void ascii_empty();

void ascii_attack_result();

void ascii_monster_turn();

void ascii_player_turn();

void ascii_player();

void ascii_critical_failure();

void ascii_failure();

void ascii_critical_success();

void ascii_success();

void ascii_monster(char * ascii);

void ascii_title();

void ascii_new_game();

void ascii_fight();

void ascii_treasure();

void ascii_chest();

#endif //CODE_ASCII_H