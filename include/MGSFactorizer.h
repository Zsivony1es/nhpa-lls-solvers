//
// Created by Peter Ivony on 28.10.23.
//

#ifndef HOMEWORK1_MGSFACTORIZER_H
#define HOMEWORK1_MGSFACTORIZER_H

#include <iostream>

#include "QRFactorizer.h"

class MGSFactorizer: QRFactorizer{
public:
    Matrix* factorize(Matrix* A) override;
};

#endif //HOMEWORK1_MGSFACTORIZER_H
