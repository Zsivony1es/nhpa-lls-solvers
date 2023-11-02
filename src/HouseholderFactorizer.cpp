//
// Created by Peter Ivony on 27.10.23.
//

#include "HouseholderFactorizer.h"

void HouseholderFactorizer::factorize(Matrix* AtoR) {
    size_t M = AtoR->row_count;
    size_t N = AtoR->col_count;

    if (M < N) {
        std::cerr << "Invalid matrix for Householder transformation: row_count was smaller than col_count!" << std::endl;
        return;
    }

    for (size_t k = 0; k < N; ++k) {
        double* u = &AtoR->entries[k * N + k]; // Pointer to the start of the k-th column of AtoR

        double norm_u = cblas_dnrm2(M - k, u, 1);
        double beta = -2.0 / (norm_u * norm_u);

        // Update the k-th column of AtoR with Householder transformation.
        cblas_dgemv(CblasRowMajor, CblasNoTrans, M - k, N - k, beta, u, N, u, 1, 1.0, &AtoR->entries[k * N + k], M);

        // Zero out the lower part of the k-th column in AtoR (R matrix)
        for (size_t i = k + 1; i < M; ++i) {
            AtoR->entries[i * N + k] = 0.0;
        }
    }

}
