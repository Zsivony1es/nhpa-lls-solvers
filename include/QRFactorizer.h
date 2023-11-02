//
// Created by Peter Ivony on 27.10.23.
//
#ifndef HOMEWORK1_QRFACTORIZER_H
#define HOMEWORK1_QRFACTORIZER_H

#include <iostream>
#include "Matrix.h"

class QRFactorizer{
public:
    virtual void factorize(Matrix* AtoR) = 0;
};

#endif //HOMEWORK1_QRFACTORIZER_H
