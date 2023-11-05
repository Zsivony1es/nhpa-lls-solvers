//
// Created by Peter Ivony on 05.11.23.
//

#ifndef HOMEWORK1_GIVENSFACTORIZER_H
#define HOMEWORK1_GIVENSFACTORIZER_H

#include "QRFactorizer.h"

class GivensFactorizer : QRFactorizer{
public:
    Matrix* factorize(Matrix* A) override;
};

#endif //HOMEWORK1_GIVENSFACTORIZER_H
