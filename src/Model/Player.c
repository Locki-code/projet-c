#include <stdlib.h>
#include <stdio.h>
#include "Header/Player.h"

Player CreatePlayer(int x_, int y_)
{
    Player nouv = malloc(sizeof(struct player_));
    nouv->pv_max = 10;
    nouv->pv = 10;
    nouv->attack = 2;
    nouv->defense = 1;
    nouv->nb_cle = 0;
    nouv->x = x_;
    nouv->y = y_;
}