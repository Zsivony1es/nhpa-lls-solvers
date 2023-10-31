//
// Created by Peter Ivony on 28.10.23.
//

#ifndef HOMEWORK1_CGSCOLUMNORTHOGONALIZER_H
#define HOMEWORK1_CGSCOLUMNORTHOGONALIZER_H

#include <iostream>
#include <cblas.h>

#include "ColumnOrthogonalizer.h"

class CGSColumnOrthogonalizer: ColumnOrthogonalizer{
public:
    void orthogonalize(Matrix* A);
};

#endif //HOMEWORK1_CGSCOLUMNORTHOGONALIZER_H
