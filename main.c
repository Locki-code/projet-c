//
// Created by Loïck on 17/05/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include "src/Reader/Header/LevelReader.h"
#include <assert.h>
#include "src/Model/Header/Matrix.h"
#include "src/Model/Matrix.c"
#include "src/Reader/LevelReader.c"

int main(int argc, char *argv[]) {
    //printf("%s", "ici 1");
    Level level = readLevelFile("C:\\Users\\MrTerminalpro\\Documents\\ISEN\\projet-c\\config\\level1.level");
    //wprintf("%lc", getElement(level->matrix, 0, 1));
    //Matrix matrix = newMatrix(5, "##^###   #<   >#   ###v##");
    printMatrix(level->matrix);
    //printf("%c", getElement(level->matrix, 2, 2));
}