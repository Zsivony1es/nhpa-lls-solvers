//
// Created by Peter Ivony on 27.10.23.
//

#include "HouseholderFactorizer.h"

std::tuple<double*, double*> HouseholderFactorizer::factorize(double* A) {
    double* ptr1 = new double(3.14);
    double* ptr2 = new double(42.0);
    return std::tuple<double*, double*>(ptr1, ptr2);
}
