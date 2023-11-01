//
// Created by Peter Ivony on 31.10.23.
//

#include "MGSColumnOrthogonalizer.h"

void MGSColumnOrthogonalizer::orthogonalize(Matrix* A){

    size_t col_count = A->col_count;
    size_t row_count = A->row_count;
    double* entries = A->entries;

    for (size_t k = 0; k < col_count; ++k) {

        double r_kk = cblas_dnrm2(row_count, &entries[k * row_count], 1);
        if (r_kk > 0.0) {
            cblas_dscal(row_count, 1.0 / r_kk, &entries[k * row_count], 1);
        }

        for (size_t j = k + 1; j < col_count; ++j) {
            double r_kj = cblas_ddot(row_count, &entries[k * row_count], 1, &entries[j * row_count], 1);
            cblas_daxpy(row_count, -r_kj, &entries[k * row_count], 1, &entries[j * row_count], 1);
        }

    }
}