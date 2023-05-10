#include <stdlib.h>
#include <stdio.h>
#include "Ennemy.h"

//Joueur principal
struct  enemy_
{
    int pv;
    int attack;
    int defense;
};
typedef struct enemy_ * Enemy;

Enemy CreateEnemy(int pv_, int attack_, int defense_)
{
    Enemy nouv = malloc(sizeof(struct enemy_));
    nouv->attack = attack_;
    nouv->pv = pv_;
    nouv->defense = defense_;
}