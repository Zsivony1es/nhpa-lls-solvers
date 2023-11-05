//
// Created by Peter Ivony on 31.10.23.
//

#include "../include/CGSFactorizer.h"

Matrix* CGSFactorizer::factorize(Matrix* A){

    size_t M = A->row_count;
    size_t N = A->col_count;
    double* entries = A->entries;

    Matrix* R = new Matrix(M, N, 0.0);

    for (size_t k = 0; k < N; ++k) {

        for (size_t j = 0; j < k; ++j) {
            double r_jk = cblas_ddot(M, &entries[j * M], 1, &entries[k * M], 1);
            R->entries[j * N + k] = r_jk;
            cblas_daxpy(M, -r_jk, &entries[j * M], 1, &entries[k * M], 1);
        }

        double r_kk = cblas_dnrm2(M, &entries[k * M], 1);

        if (r_kk > 0.0) {
            cblas_dscal(M, 1.0 / r_kk, &entries[k * M], 1);
        }
    }

    // Swap pointers to the correct matrices
    Matrix* Q = A;
    A = R;

    return Q;

}