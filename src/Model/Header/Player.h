#ifndef PLAYER_H
#define PLAYER_H

//Joueur principal
struct  player_
{
    int health_max;
    int health;
    int attack;
    int defense;
    int keys;
    int x;
    int y;
};
typedef struct player_ * Player;

Player CreatePlayer();

void resetLife(Player player);

void resetPosition(Player player);

void addDefense(Player player, int value);

void addHealthMax(Player player, int value);

#endif