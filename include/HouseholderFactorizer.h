//
// Created by Peter Ivony on 27.10.23.
//

#ifndef HOMEWORK1_HOUSEHOLDERFACTORIZER_H
#define HOMEWORK1_HOUSEHOLDERFACTORIZER_H

#include <iostream>

#include "QRFactorizer.h"

class HouseholderFactorizer: QRFactorizer{
    std::tuple<double*, double*> factorize(double* A);
};

#endif //HOMEWORK1_HOUSEHOLDERFACTORIZER_H
