#include <stdlib.h>
#include <stdio.h>
#include "Header/Enemy.h"



Enemy CreateEnemy(char name_, int pv_, int attack_, int defense_)
{
    Enemy newEnemy = malloc(sizeof(struct enemy_));
    newEnemy->name = name_;
    newEnemy->attack = attack_;
    newEnemy->pv = pv_;
    newEnemy->defense = defense_;
    return newEnemy;
}

void showStatsEnemy(Enemy enemy)
{
    int pv = enemy->pv;
    int attack = enemy->attack;
    int defense = enemy->defense;

    printf("Enemy\n------------\n pv : %d\n attack : %d\n defense : %d\n------------\n", pv, attack, defense);

    return;
}