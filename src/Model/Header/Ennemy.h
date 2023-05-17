#ifndef PLAYER_H
#define PLAYER_H

struct enemy_;

typedef struct enemy_ * Enemy;

Enemy CreateEnemy(int pv_, int attack_, int defense_);

#endif