#include <stdlib.h>
#include <stdio.h>

//Joueur principal
struct  player_
{
    int pv_max;
    int pv;
    int attack;
    int defense;
    int nb_cle;

};
typedef struct player_ * Player;

Player CreatePlayer()
{
    Player nouv = malloc(sizeof(struct player_));
    nouv->pv_max = 10;
    nouv->pv = 10;
    nouv->attack = 2;
    nouv->defense = 1;
    nouv->nb_cle = 0;
}
Player CreatePlayer()
{
    Player nouv = malloc(sizeof(struct player_));
    nouv->pv_max = 10;
    nouv->pv = 10;
    nouv->attack = 2;
    nouv->defense = 1;
    nouv->nb_cle = 0;
}