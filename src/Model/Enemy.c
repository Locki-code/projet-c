#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "Header/Enemy.h"



Enemy CreateEnemy(char name_, int health_, int attack_, int defense_){
    Enemy newEnemy = malloc(sizeof(struct enemy_));
    newEnemy->name = name_;
    newEnemy->attack = attack_;
    newEnemy->health = health_;
    newEnemy->defense = defense_;
    return newEnemy;
}

void showStatsEnemy(Enemy enemy){
    int pv = enemy->health;
    int attack = enemy->attack;
    int defense = enemy->defense;

    printf("Enemy\n------------\n pv : %d\n attack : %d\n defense : %d\n------------\n", pv, attack, defense);

    return;
}

bool isEnemyDead(Enemy enemy){
    return enemy->health <= 0;
}