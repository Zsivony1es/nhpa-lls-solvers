//
// Created by Peter Ivony on 28.10.23.
//
#include "GivensFactorizer.h"
#include <tuple>

std::tuple<double*, double*> GivensFactorizer::factorize(double* A) {
    double* ptr1 = new double(3.14);
    double* ptr2 = new double(42.0);
    return std::tuple<double*, double*>(ptr1, ptr2);
}

