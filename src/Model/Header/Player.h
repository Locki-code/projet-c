#ifndef PLAYER_H
#define PLAYER_H

//Joueur principal
struct  player_
{
    int pv_max;
    int pv;
    int attack;
    int defense;
    int nb_cle;
    int x;
    int y;
};
typedef struct player_ * Player;

Player CreatePlayer(int x_, int y_);

#endif