//
// Created by Peter Ivony on 04.11.23.
//

#include "../include/CGSSolver.h"
#include "../include/CGSFactorizer.h"

Matrix* CGSSolver::solve(Matrix* A, Matrix* b) {

    Matrix* Q = new Matrix(A);

    CGSFactorizer* factorizer = new CGSFactorizer();
    Matrix* R = factorizer->factorize(A);



}