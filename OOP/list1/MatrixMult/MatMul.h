//
// Created by pawel on 2018-10-03.
//

#ifndef MATRIXMULTIPLICATION_MATMUL_H
#define MATRIXMULTIPLICATION_MATMUL_H

double **matrixMul(double **matA, double **matB, int row, int col, int m);

double **readMatrix(int row, int col);

void printMatrix(double **matrix, int row, int col, char *s);

int dimensionsFine(int colA, int rowB);

#endif //MATRIXMULTIPLICATION_MATMUL_H