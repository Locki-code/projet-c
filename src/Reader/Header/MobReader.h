#ifndef MOBREADER_H
#define MOBREADER_H
#include <stdio.h>
#include <stdlib.h>
#include "../../Model/Header/Enemy.h"

void skipline(FILE *fp_, int t);
int getValue(FILE *fp_, int t);
Enemy * readMobFile(char * nameFile);



#endif