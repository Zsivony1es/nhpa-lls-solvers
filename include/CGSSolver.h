//
// Created by Peter Ivony on 28.10.23.
//

#ifndef HOMEWORK1_CGSSOLVER_H
#define HOMEWORK1_CGSSOLVER_H

#include <iostream>

#include "LSSSolver.h"

class CGSSolver: LSSSolver{
    std::tuple<double, double> solve();
};

#endif //HOMEWORK1_CGSSOLVER_H
