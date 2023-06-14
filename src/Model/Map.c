//
// Created by MrTerminalpro on 14/06/2023.

#include "./Header/Map.h"
#include "./Header/Map.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include "../Reader/Header/LevelReader.h"
#include "../Reader/LevelReader.c"
#include <assert.h>
#include "../Model/Matrix.c"
#include "../Model/Header/Player.h"
#include "../Model/Player.c"
#include "../Interface/Deplacement.c"

Map createMap(int nbLevel){
    Map newMap = malloc (sizeof(struct map_));
    newMap->levels = malloc(nbLevel * sizeof(struct level_));
    return newMap;
}

Level getLevelByName(char name){

}

int main(int argc, char *argv[]) {
    Map map = createMap(3);
    Level level_1 = readLevelFile("config\\level1.level","level1.level");
    Level level_2 = readLevelFile("config\\level2.level","level2.level");
    Level level_3 = readLevelFile("config\\level3.level","level3.level");
/*
    int * a;
    *a = 5;
    void b = a;
  */

    return 0;
    map->levels[0] = *level_1;
    map->levels[1] = *level_2;
    map->levels[2] = *level_3;

    printMatrix(map->levels[0].matrix);
    printMatrix(map->levels[1].matrix);
    printMatrix(map->levels[2].matrix);
}