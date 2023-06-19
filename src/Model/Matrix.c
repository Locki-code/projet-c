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

int printMatrix(Matrix mtx, Player player) {
    if (!mtx) return -1;

    int row, col;
    printf("\n");
    for (row = 1; row <= mtx->rowSize; row++) {
        for (col = 1; col <= mtx->rowSize; col++) {
            if((row == 1 || row == 6 ) && col == 30){
                printf("%c \t\t<---------------->", mtx->data[(row-1) * mtx->rowSize + (col-1)]);
            } else if(row == 2 && col == 30){
                printf("%c \t\t Health : %d / %d", mtx->data[(row-1) * mtx->rowSize + (col-1)], player->health, player->health_max);
            } else if(row == 3 && col == 30){
                printf("%c \t\t Attack : %d", mtx->data[(row-1) * mtx->rowSize + (col-1)], player->attack);
            } else if(row == 4 && col == 30){
                printf("%c \t\t Defense : %d", mtx->data[(row-1) * mtx->rowSize + (col-1)], player->defense);
            } else if(row == 5 && col == 30){
                printf("%c \t\t Keys : %d", mtx->data[(row-1) * mtx->rowSize + (col-1)], player->keys);
            } else {
                printf("%c ", mtx->data[(row-1) * mtx->rowSize + (col-1)]);
            }
        }
        printf("\n");
    }

    return 0;
}