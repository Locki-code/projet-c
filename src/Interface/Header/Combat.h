#ifndef COMBAT_H
#define COMBAT_H

#include "../../Model/Header/Player.h"
#include "../../Model/Header/Enemy.h"

void isDead(Player p, Enemy e);

void executeRound(Player p, Enemy e);

void actionInterface(Player p, Enemy e);

#endif