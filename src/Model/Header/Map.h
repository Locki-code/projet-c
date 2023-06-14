//
// Created by MrTerminalpro on 14/06/2023.
//

#include "Level.h"

#ifndef PROJET_C_MAP_H
#define PROJET_C_MAP_H

struct map_ {
    struct level_ * levels;
};

typedef struct map_ * Map;

Map createMap();

Level getLevelByName(char name);


#endif //PROJET_C_MAP_H
