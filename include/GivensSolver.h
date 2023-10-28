//
// Created by Peter Ivony on 28.10.23.
//

#ifndef HOMEWORK1_GIVENSSOLVER_H
#define HOMEWORK1_GIVENSSOLVER_H

#include <iostream>

#include "LSSSolver.h"

class GivensSolver: LSSSolver{
    std::tuple<double, double> solve();
};

#endif //HOMEWORK1_GIVENSSOLVER_H
