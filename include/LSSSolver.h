//
// Created by Peter Ivony on 04.11.23.
//

#ifndef HOMEWORK1_LSSSOLVER_H
#define HOMEWORK1_LSSSOLVER_H

#include "Matrix.h"

class LSSSolver{
public:
    virtual Matrix* solve(Matrix* A, Matrix* b) = 0;
};

#endif //HOMEWORK1_LSSSOLVER_H
