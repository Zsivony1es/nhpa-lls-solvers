//
// Created by Peter Ivony on 28.10.23.
//

#include "GivensFactorizer.h"
#include <cblas.h>

Matrix* GivensFactorizer::factorize(Matrix* AtoR) {
    int M = AtoR->row_count;
    int N = AtoR->col_count;
    int min_MN = M < N ? M : N;

    double* A = AtoR->entries; // Pointer to the matrix entries

    for (int j = 0; j < min_MN; j++) {
        for (int i = M - 1; i > j; i--) {
            // Compute the Givens rotation parameters
            double a = A[i * N + j];
            double b = A[(i - 1) * N + j];
            double r = sqrt(a * a + b * b);
            double c = a / r;
            double s = -b / r;

            // Apply the Givens rotation to the submatrix A(i-1:i+1, j:n)
            cblas_drot(N - j, &A[i * N + j], 1, &A[(i - 1) * N + j], 1, c, s);

            // Update the R factor (upper triangular part)
            A[(i - 1) * N + j] = r;

            // Update the submatrix A(i, j:n) to zero out the lower part
            A[i * N + j] = 0.0;
        }
    }
}

