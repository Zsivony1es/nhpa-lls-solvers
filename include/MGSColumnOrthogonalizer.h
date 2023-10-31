//
// Created by Peter Ivony on 28.10.23.
//

#ifndef HOMEWORK1_MGSCOLUMNORTHOGONALIZER_H
#define HOMEWORK1_MGSCOLUMNORTHOGONALIZER_H

#include <iostream>

#include "ColumnOrthogonalizer.h"

class MGSColumnOrthogonalizer: ColumnOrthogonalizer{
public:
    void orthogonalize(Matrix* A);
};

#endif //HOMEWORK1_MGSCOLUMNORTHOGONALIZER_H
