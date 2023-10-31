//
// Created by Peter Ivony on 31.10.23.
//

#ifndef HOMEWORK1_ORTHOGONALIZER_H
#define HOMEWORK1_ORTHOGONALIZER_H

#include "Matrix.h"

class ColumnOrthogonalizer{
public:
    virtual void orthogonalize(Matrix* A) = 0;
};

#endif //HOMEWORK1_ORTHOGONALIZER_H
