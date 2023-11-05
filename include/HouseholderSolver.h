//
// Created by Peter Ivony on 27.10.23.
//

#ifndef HOMEWORK1_HOUSEHOLDERSOLVER_H
#define HOMEWORK1_HOUSEHOLDERSOLVER_H

#include <iostream>

#include "LLSSolver.h"

class HouseholderSolver: LSSSolver{
public:
    Matrix* solve(Matrix* A, Matrix* b) override;
};

#endif //HOMEWORK1_HOUSEHOLDERSOLVER_H
