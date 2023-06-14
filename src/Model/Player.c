#include <stdlib.h>
#include <stdio.h>
#include "Header/Player.h"

Player CreatePlayer()
{
    Player newPlayer = malloc(sizeof(struct player_));
    newPlayer->health_max = 10;
    newPlayer->health = 10;
    newPlayer->attack = 2;
    newPlayer->defense = 1;
    newPlayer->keys = 0;
    newPlayer->x = 15;
    newPlayer->y = 2;
    return newPlayer;
}

void showStatsPlayer(Player player)
{
    int health = player->health;
    int health_max = player->health_max;
    int attack = player->attack;
    int defense = player->defense;
    int keys = player->keys;

    printf(
            "Player\n------------\n Health : %d/%d\n attack : %d\n defense : %d\n keys : %d\n------------\n",
            health, health_max, attack, defense, keys);
}

void resetLife(Player player){
    player->health = player->health_max;
}

void resetPosition(Player player){
    player->x = 15;
    player->y = 2;
}

void addDefense(Player player, int value){
    player->defense = player->defense + value;
}

void addHealthMax(Player player, int value){
    player->health_max = player->health_max + value;
}