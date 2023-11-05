//
// Created by Peter Ivony on 31.10.23.
//

#ifndef HOMEWORK1_QRFACTORIZER_H
#define HOMEWORK1_QRFACTORIZER_H

#include "Matrix.h"

class QRFactorizer {
public:
    // Transforms A to R and returns pointer to Q
    virtual Matrix* factorize(Matrix* A) = 0;
};

#endif //HOMEWORK1_QRFACTORIZER_H
