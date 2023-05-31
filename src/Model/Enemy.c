#include <stdlib.h>
#include <stdio.h>
#include "Header/Enemy.h"



Enemy CreateEnemy(char name_, int pv_, int attack_, int defense_)
{
    Enemy nouv = malloc(sizeof(struct enemy_));
    nouv->name = name_;
    nouv->attack = attack_;
    nouv->pv = pv_;
    nouv->defense = defense_;
}

void statsEnemy(Enemy enemy)
{
    int pv = enemy->pv;
    int attack = enemy->attack;
    int defense = enemy->defense;

    printf("Enemy\n------------\n pv : %d\n attack : %d\n defense : %d\n------------\n", pv, attack, defense);

    return;
}