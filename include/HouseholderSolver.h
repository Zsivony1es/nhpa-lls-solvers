//
// Created by Peter Ivony on 27.10.23.
//

#ifndef HOMEWORK1_HOUSEHOLDERSOLVER_H
#define HOMEWORK1_HOUSEHOLDERSOLVER_H

#include <iostream>

#include "LSSSolver.h"

class HouseholderSolver: LSSSolver{
    std::tuple<double, double> solve();
};

#endif //HOMEWORK1_HOUSEHOLDERSOLVER_H
