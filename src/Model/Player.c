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

void statsPlayer(Player player)
{
    int pv = player->pv;
    int attack = player->attack;
    int defense = player->defense;

    printf("Player\n------------\n pv : %d\n attack : %d\n defense : %d\n------------\n", pv, attack, defense);

    return;
}