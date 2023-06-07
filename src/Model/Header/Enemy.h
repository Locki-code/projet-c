#ifndef ENEMY_H
#define ENEMY_H
#include <stdio.h>
#include <stdlib.h>

//Joueur principal
struct enemy_
{
    char name;
    int pv;
    int attack;
    int defense;
    int x;
    int y;
};

typedef struct enemy_ * Enemy;

Enemy CreateEnemy(char name_, int pv_, int attack_, int defense_, int x_, int y_);

void showStatsEnemy(Enemy enemy);

#endif