#ifndef PROJET_C_LEVEL_H
#define PROJET_C_LEVEL_H

#include "Matrix.h"

struct level_ {
    char* filename;
    Matrix matrix;
    char* filename_north;
    char* filename_east;
    char* filename_south;
    char* filename_west;
};

typedef struct level_ * Level;

Level createLevel(char* filename, Matrix matrix, char* filename_north, char* filename_east, char* filename_south, char* filename_west);

#endif //PROJET_C_LEVEL_H
