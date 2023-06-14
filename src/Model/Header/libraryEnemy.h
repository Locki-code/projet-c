#ifndef LIBRARYENEMY_H
#define LIBRARYENEMY_H
#include <stdio.h>
#include <stdlib.h>
#include "Enemy.h"

struct libraryenemy_
{
    Enemy tab[5];
    int count;
};

typedef struct libraryenemy_ * LibraryEnemy;
LibraryEnemy CreateLibraryEnemy();
void addEnemy(LibraryEnemy lib, Enemy e);
Enemy findByName(LibraryEnemy lib,  char name);


#endif