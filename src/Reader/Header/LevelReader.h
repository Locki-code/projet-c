#ifndef PROJET_C_LEVELREADER_H
#define PROJET_C_LEVELREADER_H

#include "../../Model/Header/Level.h"

char * removeSpacesFromStr(char *string);

Level ReadLevelFile(char* filename);

#endif //PROJET_C_LEVELREADER_H
