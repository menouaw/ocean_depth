//
// Created by menou on 11/11/2025.
//

#ifndef CODE_BASES_H
#define CODE_BASES_H

typedef struct Map
{
    int nb_level;
    int room_by_level;
    char ** map;
} Map;

typedef struct Position
{
    int level, room;
} Position;

typedef struct Player
{
    int score;
    Map map;
    Position position;
    int max_hp;
    int current_hp;
    int strength;
    int defense;
    int speed;
    int max_breathe;
    int current_breathe;
    int exhaust;
    int money;
} Player;

typedef struct Monster
{
    int id;
    char name[30];
    int max_hp;
    int current_hp;
    int min_strength;
    int max_strength;
    int defense;
    int speed;
    char special_power[30];
} Monster;

#endif //CODE_BASES_H