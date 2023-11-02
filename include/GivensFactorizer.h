//
// Created by Peter Ivony on 28.10.23.
//

#ifndef HOMEWORK1_GIVENSFACTORIZER_H
#define HOMEWORK1_GIVENSFACTORIZER_H

#include <iostream>

#include "QRFactorizer.h"

class GivensFactorizer: QRFactorizer{
public:
    void factorize(Matrix* AtoR);
};

#endif //HOMEWORK1_GIVENSFACTORIZER_H
