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