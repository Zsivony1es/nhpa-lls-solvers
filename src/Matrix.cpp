//
// Created by Peter Ivony on 31.10.23.
//

#include "Matrix.h"

std::default_random_engine Matrix::generator = std::default_random_engine(1234);

Matrix::Matrix(size_t col_count, size_t row_count) : col_count(col_count), row_count(row_count) {

    this->entries = new double[col_count * row_count];

    std::uniform_real_distribution<double> distribution(-1, 1);

    for (size_t i = 0; i < col_count * row_count; ++i){
        this->entries[i] = distribution(this->generator);
    }
}

// Reads in a matrix from a file, which contains the exact output of the to_string method
Matrix::Matrix(std::string src_file_path){

    std::ifstream file(src_file_path);
    if (!file.is_open()) {
        std::cerr << "Failed to open the file: " << src_file_path << std::endl;
        return;
    }

    std::vector<std::vector<double>> matrixData;
    std::string line;

    bool first_line = true;
    size_t entry_index = 0;

    while (std::getline(file, line)) {
        std::stringstream ss(line);

        if (first_line){
            char x;
            first_line = false;
            ss >> x; // Read '('
            ss >> this->row_count;
            ss >> x; // Read 'x'
            ss >> this->col_count;
            this->entries = new double[this->row_count * this->col_count];
            continue;
        }

        double entry;
        while (ss >> entry) {
            this->entries[entry_index++] = entry;
            char c;
            ss >> c; // Read ','
        }
    }
}

Matrix::~Matrix() {
    delete[] this->entries;
}

std::string Matrix::to_string() const {
    std::stringstream ss;
    ss << "(" << this->row_count << "x" << this->col_count << ")\n";
    for (size_t i = 0; i < this->row_count; i++) {
        for (size_t j = 0; j < this->col_count; j++) {
            ss << this->entries[i * this->col_count + j];
            if (j < this->col_count - 1) {
                ss << ", ";
            }
        }
        if (i < this->row_count - 1) {
            ss << "\n";
        }
    }
    return ss.str();
}