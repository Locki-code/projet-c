#ifndef PROJET_C_MATRIX_H
#define PROJET_C_MATRIX_H

typedef struct {
    int rowSize;
    char* data;
} Matrix;

Matrix * newMatrix(int rowSize, char* data);

void setElement(Matrix * mtx, int row, int col, char val);

char getElement(Matrix * mtx, int row, int col);

int printMatrix(Matrix * mtx);

#endif //PROJET_C_MATRIX_H
