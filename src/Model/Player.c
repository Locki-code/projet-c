#include <stdlib.h>
#include <stdio.h>
#include "Header/Player.h"

Position CreatePosition(x_, y_){
    Position pos = malloc(sizeof(struct position_));
    pos -> x = x_;
    pos -> y = y_;
}

Player CreatePlayer(int x_, int y_)
{
    Player nouv = malloc(sizeof(struct player_));
    nouv->pv_max = 10;
    nouv->pv = 10;
    nouv->attack = 2;
    nouv->defense = 1;
    nouv->nb_cle = 0;
    nouv->pos = CreatePosition(x_, y_);
}