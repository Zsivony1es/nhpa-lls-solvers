//
// Created by Peter Ivony on 04.11.23.
//

#ifndef HOMEWORK1_MGSSOLVER_H
#define HOMEWORK1_MGSSOLVER_H

#include "LSSSolver.h"

class MGSSolver : LSSSolver{
public:
    Matrix* solve(Matrix* A, Matrix* b) override;
};

#endif //HOMEWORK1_MGSSOLVER_H
