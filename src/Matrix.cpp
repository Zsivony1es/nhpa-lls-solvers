//
// Created by Peter Ivony on 31.10.23.
//

#include "Matrix.h"

#include <random>

Matrix::Matrix(size_t col_count, size_t row_count) : col_count(col_count), row_count(row_count) {

    this->entries = new double[col_count * row_count];

    std::random_device rd;
    std::default_random_engine generator(rd());
    std::uniform_real_distribution<double> distribution(-1, 1);

    for (size_t i = 0; i < col_count * row_count; ++i){
        this->entries[i] = distribution(generator);
    }
}

Matrix::~Matrix() {
    delete[] this->entries;
}

double* Matrix::get_entries() const{
    return this->entries;
}

std::string Matrix::to_string() const {
    std::stringstream ss;
    ss << "[";
    for (size_t i = 0; i < this->row_count; i++) {
        ss << "[";
        for (size_t j = 0; j < this->col_count; j++) {
            ss << this->entries[i * this->col_count + j];
            if (j < this->col_count - 1) {
                ss << ", ";
            }
        }
        ss << "]";
        if (i < this->row_count - 1) {
            ss << ",\n";
        }
    }
    ss << "]";
    return ss.str();
}