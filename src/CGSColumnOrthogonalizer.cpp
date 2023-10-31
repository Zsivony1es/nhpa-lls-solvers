//
// Created by Peter Ivony on 31.10.23.
//

#include "CGSColumnOrthogonalizer.h"
#include <cblas.h>

void CGSColumnOrthogonalizer::orthogonalize(Matrix* A){
    size_t col_count = A->col_count;
    size_t row_count = A->row_count;
    double* entries = A->entries;

    for (size_t j = 0; j < col_count; ++j) {

        for (size_t k = 0; k < j; ++k) {
            double dot_product = cblas_ddot(row_count, &entries[j * row_count], 1, &entries[k * row_count], 1);

            // Subtract the projection of column j onto column k from column j
            cblas_daxpy(row_count, -dot_product, &entries[k * row_count], 1, &entries[j * row_count], 1);
        }

        // Normalize the j-th column vector
        double norm = cblas_dnrm2(row_count, &entries[j * row_count], 1);

        if (norm > 0.0) {
            cblas_dscal(row_count, 1.0 / norm, &entries[j * row_count], 1);
        }
    }
}