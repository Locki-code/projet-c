#include "Header/Matrix.h"
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

/* Creates a ``rows by cols'' matrix with all values 0.
 * Returns NULL if rows <= 0 or cols <= 0 and otherwise a
 * pointer to the new matrix.
 */
Matrix newMatrix(int rowSize_, char* data_) {
    // allocate a matrix structure
    Matrix matrix = malloc(sizeof(struct matrix_));

    matrix->rowSize = rowSize_;
    matrix->data = data_;

    return matrix;
}

void setElement(Matrix mtx, int row, int col, char val) {
    mtx->data[(row-1) * mtx->rowSize + (col-1)] = val;
}

char getElement(Matrix mtx, int row, int col) {
    return mtx->data[(row-1) * mtx->rowSize + (col-1)];
}

int printMatrix(Matrix mtx) {
    if (!mtx) return -1;

    int row, col;
    printf("\n");
    for (row = 1; row <= mtx->rowSize; row++) {
        for (col = 1; col <= mtx->rowSize; col++) {
            printf("%c", mtx->data[(row-1) * mtx->rowSize + (col-1)]);
        }
        printf("\n");
    }

    return 0;
}