//
// Created by Peter Ivony on 31.10.23.
//

#include "CGSColumnOrthogonalizer.h"

void CGSColumnOrthogonalizer::orthogonalize(Matrix* A){

    size_t col_count = A->col_count;
    size_t row_count = A->row_count;
    double* entries = A->entries;

    for (size_t k = 0; k < col_count; ++k) {

        for (size_t j = 0; j < k; ++j) {
            double r_jk = cblas_ddot(row_count, &entries[j * row_count], 1, &entries[k * row_count], 1);
            cblas_daxpy(row_count, -r_jk, &entries[j * row_count], 1, &entries[k * row_count], 1);
        }

        double r_kk = cblas_dnrm2(row_count, &entries[k * row_count], 1);

        if (r_kk > 0.0) {
            cblas_dscal(row_count, 1.0 / r_kk, &entries[k * row_count], 1);
        }
    }
}