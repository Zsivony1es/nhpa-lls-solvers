//
// Created by Peter Ivony on 28.10.23.
//

#ifndef HOMEWORK1_MGSSOLVER_H
#define HOMEWORK1_MGSSOLVER_H

#include <iostream>

#include "LSSSolver.h"

class MGSSolver: LSSSolver{
    std::tuple<double, double> solve();
};

#endif //HOMEWORK1_MGSSOLVER_H
