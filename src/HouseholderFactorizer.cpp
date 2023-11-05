//
// Created by Peter Ivony on 05.11.23.
//

#include "../include/HouseholderFactorizer.h"

Matrix* HouseholderFactorizer::factorize(Matrix* A) {

    size_t M = A->row_count;
    size_t N = A->col_count;

    if (M < N) {
        std::cerr << "Invalid matrix for Householder transformation: row_count was smaller than col_count!" << std::endl;
        return nullptr;
    }

    Matrix* QT = new Matrix();
    QT->initialize_identity(M);

    for (size_t k = 0; k < N; ++k) {

        double* u = &A->entries[k];
        double norm_u = cblas_dnrm2(M, u, N);

        // Construct v
        Matrix* v = new Matrix(M, 1);
        for (size_t i = 0; i < M; ++i){
            v->entries[i] = A->entries[k + N * i];
        }
        if (v->entries[k] > 0){
            v->entries[k] += norm_u;
        } else {
            v->entries[k] -= norm_u;
        }
        double norm_v = cblas_dnrm2(M, v->entries, 1);
        for (size_t i = 0; i < M; ++i){
            v->entries[i] /= norm_v;
        }

        // Construct H_k
        Matrix* Hk = new Matrix();
        Hk->initialize_identity(M);
        // Construct outer product of vv^T and subtract its scalar multiple from identity to get H_k
        cblas_dger(CblasRowMajor, M, M, -2.0 / norm_v, v->entries, 1, v->entries, 1, Hk->entries, M);

        std::cout << "k=" << k << " " << v->to_string() << "\n" << A->to_string() << std::endl;

        // A=Hk, B=A, C=temp
        Matrix* temp1 = new Matrix(M, N, 0.0);
        // Apply householder k to A
        cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
                    M, N, M, 1.0, Hk->entries, M, A->entries, M, 1.0, temp1->entries, M);
        std::cout << temp1->to_string() << std::endl;
        A->set_entries(temp1->entries);

        // Apply householder k to accumulator matrix
        Matrix* temp2 = new Matrix(M, M, 0.0);
        cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
                    M, M, M, 1.0, Hk->entries, M, QT->entries, M, 1.0, temp2->entries, M);
        std::cout << temp2->to_string() << std::endl;
        QT->set_entries(temp2->entries);

        // Zero out lower part of vector in A
        for (size_t i = k+1; i < M; ++i){
            A->entries[k + N * i] = 0.0;
        }

        std::cout << A->to_string() << std::endl;

    }

    QT->transpose();
    return QT;

}

