//
// Created by Peter Ivony on 31.10.23.
//

#ifndef HOMEWORK1_MATRIX_H
#define HOMEWORK1_MATRIX_H

#include <string>
#include <sstream>

class Matrix {
private:
    size_t col_count, row_count;
    double* entries;
public:
    Matrix(size_t col_count, size_t row_count);
    ~Matrix();
    double* get_entries() const;
    std::string to_string() const;
};


#endif //HOMEWORK1_MATRIX_H