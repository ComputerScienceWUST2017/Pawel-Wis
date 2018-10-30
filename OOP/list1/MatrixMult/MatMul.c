//
// Created by pawel on 2018-10-03.
//

#include <malloc.h>
#include <stdio.h>
#include "MatMul.h"

double **matrixMul(double **matA, double **matB, int row, int col, int m) {
    int i, j, k;
    double **result = malloc(row * sizeof(double *));
    for (i = 0; i < row; ++i) {
        result[i] = malloc(col * sizeof(double));
        for (j = 0; j < col; ++j) {
            result[i][j] = 0;
            for (k = 0; k < m; ++k) {
                result[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }
    return result;
}


double **readMatrix(int row, int col) {
    double **matrix = malloc(row * sizeof(double *));
    int i, j;
    for (i = 0; i < row; ++i) {
        matrix[i] = malloc(col * sizeof(double));
        for (j = 0; j < col; ++j) {
            if(scanf("%lf", &matrix[i][j]) == 0){
                printf("\nWrong input!\n");
                return NULL;
            }
        }
    }
    return matrix;
}

void printMatrix(double **matrix, int row, int col, char *c) {
    printf("\nPrinting matrix %s:\n", c);
    int i, j;
    for (i = 0; i < row; ++i) {
        for (j = 0; j < col; ++j) {
            printf("%.2lf%c", matrix[i][j], j + 1 == col ? '\n' : ' ');
        }
    }
}

int dimensionsFine(int colA, int rowB) {
    return colA == rowB;
}