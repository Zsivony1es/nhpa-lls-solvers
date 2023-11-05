//
// Created by Peter Ivony on 05.11.23.
//

#include "../include/GivensFactorizer.h"

Matrix* GivensFactorizer::factorize(Matrix *A) {
    int M = A->row_count;
    int N = A->col_count;
    int min_MN = M < N ? M : N;

    for (int j = 0; j < min_MN; j++) {
        for (int i = M - 1; i > j; i--) {

            double a = A->entries[i * N + j];
            double b = A->entries[(i - 1) * N + j];
            double r = sqrt(a * a + b * b);
            double c = a / r;
            double s = -b / r;

            cblas_drot(N - j, &A->entries[i * N + j], 1, &A->entries[(i - 1) * N + j], 1, c, s);

            A->entries[(i - 1) * N + j] = r;

            A->entries[i * N + j] = 0.0;
        }
    }
}