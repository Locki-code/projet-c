#ifndef ENEMY_H
#define ENEMY_H
#include <stdio.h>
#include <stdlib.h>

//Joueur principal
struct enemy_
{
    char name;
    int health;
    int attack;
    int defense;
};

typedef struct enemy_ * Enemy;

Enemy CreateEnemy(char name_, int health_, int attack_, int defense_);

void showStatsEnemy(Enemy enemy);

bool isEnemyDead(Enemy enemy);
#endif