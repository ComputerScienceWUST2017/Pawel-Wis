#include <stdio.h>
#include "MatMul.h"

int main() {

    int rowA, colA, rowB, colB;

    scanf("%d %d", &rowA, &colA);
    double **a = readMatrix(rowA, colA);
    if(a == NULL) return 1;

    scanf("%d %d", &rowB, &colB);
    double **b = readMatrix(rowB, colB);
    if(b == NULL) return 1;

    double **result;
    if (dimensionsFine(colA, rowB)) {
        result = matrixMul(a, b, rowA, colB, rowB);
        printMatrix(a, rowA, colA, "A");
        printMatrix(b, rowB, colB, "B");
        printMatrix(result, rowA, colB, "A*B");
    } else {
        printf("\nWrong dimensions!\n");
    }
    return 0;
}