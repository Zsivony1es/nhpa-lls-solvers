//
// Created by Peter Ivony on 27.10.23.
//

#include "../include/HouseholderSolver.h"

Matrix* HouseholderSolver::solve(Matrix* A, Matrix* b) {

    size_t M = A->row_count;
    size_t N = A->col_count;

    if (M < N) {
        std::cerr << "Invalid matrix for Householder transformation: row_count was smaller than col_count!" << std::endl;
        return nullptr;
    }

    for (size_t k = 0; k < N; ++k) {

        double* u = &A->entries[k];
        double norm_u = cblas_dnrm2(M, u, N);

        // Construct v
        Matrix* v = new Matrix(M, 1);
        for (size_t i = 0; i < M; ++i){
            v->entries[i] = A->entries[k + N * i] / norm_u;
        }
        if (v->entries[k] > 0){
            v->entries[k] += 1;
        } else {
            v->entries[k] -= 1;
        }

        std::cout << "k=" << k << " " << v->to_string() << "\n" << A->to_string() << std::endl;

        // Apply householder to b

        // Apply householder to A


        // Zero out lower part of vector in A
        for (size_t i = k+1; i < M; ++i){
            A->entries[k + N * i] = 0.0;
        }

        std::cout << A->to_string() << std::endl;

    }

}
