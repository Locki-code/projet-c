#ifndef COMBAT_H
#define COMBAT_H

#include "../../Model/Header/Player.h"
#include "../../Model/Header/Enemy.h"

void isDead(Player p, Enemy e);

void pvDown(Player p, Enemy e);

void action(Player p, Enemy e);

#endif