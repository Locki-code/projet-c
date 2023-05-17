#include <stdlib.h>
#include <stdio.h>
#include "Header/Ennemy.h"



Enemy CreateEnemy(int pv_, int attack_, int defense_)
{
    Enemy nouv = malloc(sizeof(struct enemy_));
    nouv->attack = attack_;
    nouv->pv = pv_;
    nouv->defense = defense_;
}