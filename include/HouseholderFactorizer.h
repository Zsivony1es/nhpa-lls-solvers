//
// Created by Peter Ivony on 27.10.23.
//

#ifndef HOMEWORK1_HOUSEHOLDERFACTORIZER_H
#define HOMEWORK1_HOUSEHOLDERFACTORIZER_H

#include <iostream>

#include "QRFactorizer.h"

class HouseholderFactorizer: QRFactorizer{
public:
    Matrix* factorize(Matrix* AtoR);
};

#endif //HOMEWORK1_HOUSEHOLDERFACTORIZER_H
