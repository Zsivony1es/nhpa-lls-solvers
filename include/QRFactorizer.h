//
// Created by Peter Ivony on 27.10.23.
//
#ifndef HOMEWORK1_QRFACTORIZER_H
#define HOMEWORK1_QRFACTORIZER_H

#include <iostream>

class QRFactorizer{
public:
    virtual std::tuple<double*, double*> factorize(double* A) = 0;
};

#endif //HOMEWORK1_QRFACTORIZER_H
