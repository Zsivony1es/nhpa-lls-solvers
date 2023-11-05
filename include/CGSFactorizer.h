//
// Created by Peter Ivony on 28.10.23.
//

#ifndef HOMEWORK1_CGSFACTORIZER_H
#define HOMEWORK1_CGSFACTORIZER_H

#include "QRFactorizer.h"

class CGSFactorizer: QRFactorizer{
public:
    Matrix* factorize(Matrix* A) override;
};

#endif //HOMEWORK1_CGSFACTORIZER_H
