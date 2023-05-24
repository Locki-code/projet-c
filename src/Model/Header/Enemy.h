#ifndef PLAYER_H
#define PLAYER_H

//Joueur principal
struct  enemy_
{
    int pv;
    int attack;
    int defense;
};
typedef struct enemy_ * Enemy;

Enemy CreateEnemy(int pv_, int attack_, int defense_);

#endif