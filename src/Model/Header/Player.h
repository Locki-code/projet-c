#ifndef PLAYER_H
#define PLAYER_H

//position
struct position_
{
    int x;
    int y;
};
typedef struct position_ * Position;

Position CreatePosition(x_, y_);

//Joueur principal
struct  player_
{
    int pv_max;
    int pv;
    int attack;
    int defense;
    int nb_cle;
    Position pos;
};
typedef struct player_ * Player;

Player CreatePlayer();

#endif