//
// Created by Peter Ivony on 27.10.23.
//

#include "HouseholderFactorizer.h"

Matrix* HouseholderFactorizer::factorize(Matrix* AtoR) {
    size_t M = AtoR->row_count;
    size_t N = AtoR->col_count;

    if (M < N) {
        std::cerr << "Invalid matrix for Householder transformation: row_count was smaller than col_count!" << std::endl;
        return nullptr;
    }

    Matrix* Q = new Matrix();
    Q->initialize_identity(N);

    for (size_t k = 0; k < N; ++k) {
        double* u = &AtoR->entries[k]; // Pointer to the start of the k-th column of AtoR

        double norm_u = cblas_dnrm2(M - k, u, N);
        double beta = -2.0 / (norm_u * norm_u);

        // Update the k-th column of AtoR with Householder transformation
        cblas_dgemv(CblasRowMajor, CblasNoTrans, M - k, N - k, beta, u, N, u, 1, 1.0, &AtoR->entries[k * N + k], M);

        // Zero out the lower part of the k-th column in AtoR (R matrix)
        for (size_t i = k + 1; i < M; ++i) {
            AtoR->entries[i * N + k] = 0.0;
        }

        // Update the Q matrix with the Householder transformation
        double Q_scalar = -2.0 / (norm_u * norm_u);
        cblas_dger(CblasRowMajor, M, M, Q_scalar, u, 1, u, 1, Q->entries, M);
    }

    // Normalize the Q matrix
    for (size_t k = 0; k < N; ++k) {
        double norm_column_k = cblas_dnrm2(M, &Q->entries[k * M], 1);
        for (size_t i = 0; i < M; ++i) {
            Q->entries[i * M + k] /= norm_column_k;
        }
    }

    return Q;
}
