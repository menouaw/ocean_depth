//
// Created by menou on 11/11/2025.
//

#ifndef CODE_BASES_H
#define CODE_BASES_H

typedef struct Player
{
    int max_pov;
    int current_pov;
    int max_breathe;
    int current_breathe;
    int exhaust;
    int money;
} Player;

typedef struct Monster
{
    int id;
    char name[30];
    int max_pov;
    int current_pov;
    int min_strength;
    int max_strength;
    int defense;
    int speed;
    int is_alive;
    // TODO: gérer les capacités spéciales
} Monster;

#endif //CODE_BASES_H