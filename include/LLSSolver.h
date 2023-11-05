//
// Created by Peter Ivony on 04.11.23.
//

#ifndef HOMEWORK1_LLSSOLVER_H
#define HOMEWORK1_LLSSOLVER_H

#include "Matrix.h"

class LLSSolver{
public:
    // Returns the x vector (solution to the LLS)
    virtual Matrix* solve(Matrix* A, Matrix* b) = 0;
};

#endif //HOMEWORK1_LLSSOLVER_H
