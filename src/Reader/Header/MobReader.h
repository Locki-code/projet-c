#ifndef MOBREADER_H
#define MOBREADER_H
#include <stdio.h>
#include <stdlib.h>
#include "../../Model/Header/Enemy.h"
#include "../../Model/Header/libraryEnemy.h"

int getDigit(char * def);
Enemy readMob(FILE * fp);
LibraryEnemy readAllMobs(FILE * fp);
void printMob(Enemy en);



#endif