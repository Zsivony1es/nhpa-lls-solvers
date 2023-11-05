//
// Created by Peter Ivony on 28.10.23.
//

#ifndef HOMEWORK1_GIVENSSOLVER_H
#define HOMEWORK1_GIVENSSOLVER_H

#include "LLSSolver.h"

class GivensSolver: LSSSolver{
public:
    Matrix* solve(Matrix* A, Matrix* b) override;
};

#endif //HOMEWORK1_GIVENSSOLVER_H
