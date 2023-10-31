//
// Created by Peter Ivony on 31.10.23.
//

#ifndef HOMEWORK1_MATRIX_H
#define HOMEWORK1_MATRIX_H

#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <random>
#include <cmath>
#include <cblas.h>


class Matrix {
private:
    static std::default_random_engine generator;
public:
    size_t col_count, row_count;
    double* entries;

    Matrix(size_t col_count, size_t row_count);
    Matrix(std::string src_file_path);
    ~Matrix();
    double evaluate_orthogonality() const;
    std::string to_string() const;
};


#endif //HOMEWORK1_MATRIX_H
