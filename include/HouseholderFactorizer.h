//
// Created by Peter Ivony on 05.11.23.
//

#ifndef HOMEWORK1_HOUSEHOLDERFACTORIZER_H
#define HOMEWORK1_HOUSEHOLDERFACTORIZER_H

#include "QRFactorizer.h"

class HouseholderFactorizer : QRFactorizer{
public:
    Matrix* factorize(Matrix* A) override;

};

#endif //HOMEWORK1_HOUSEHOLDERFACTORIZER_H
