//
// Created by Peter Ivony on 04.11.23.
//

#ifndef HOMEWORK1_CGSSOLVER_H
#define HOMEWORK1_CGSSOLVER_H

#include "LLSSolver.h"

class CGSSolver : LSSSolver{
public:
    Matrix* solve(Matrix* A, Matrix* b) override;
};

#endif //HOMEWORK1_CGSSOLVER_H
