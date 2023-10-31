//
// Created by Peter Ivony on 28.10.23.
//

#ifndef HOMEWORK1_GIVENSFACTORIZER_H
#define HOMEWORK1_GIVENSFACTORIZER_H

#include <iostream>

#include "QRFactorizer.h"

class GivensFactorizer: QRFactorizer{
    std::tuple<double*, double*> factorize(double* A);
};

#endif //HOMEWORK1_GIVENSFACTORIZER_H
