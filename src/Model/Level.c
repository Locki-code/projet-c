#include "Header/Level.h"
#include <stdio.h>
#include <stdlib.h>
#include "Header/Matrix.h"

Level createLevel(
        char filename,
        Matrix matrix,
        char filename_north,
        char filename_east,
        char filename_south,
        char filename_west
        ){
    Level newLevel = malloc(sizeof(struct level_));
    newLevel->filename = &filename;
    newLevel->matrix = matrix;
    newLevel->filename_north = &filename_north;
    newLevel->filename_east = &filename_east;
    newLevel->filename_south = &filename_south;
    newLevel->filename_west = &filename_west;
    return newLevel;
}
