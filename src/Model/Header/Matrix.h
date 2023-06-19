#ifndef PROJET_C_MATRIX_H
#define PROJET_C_MATRIX_H

#include "Player.h"

struct matrix_ {
    int rowSize;
    char* data;
};

typedef struct matrix_ * Matrix;

Matrix newMatrix(int rowSize, char * data);

void setElement(Matrix mtx, int row, int col, char val);

char getElement(Matrix mtx, int row, int col);

int printMatrix(Matrix mtx, Player player);

#endif //PROJET_C_MATRIX_H
