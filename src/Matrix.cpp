//
// Created by Peter Ivony on 31.10.23.
//

#include "../include/Matrix.h"

std::default_random_engine Matrix::generator = std::default_random_engine(1234);

Matrix::Matrix(){
    this->row_count = 0;
    this->col_count = 0;
    this->entries = nullptr;
}

Matrix::Matrix(Matrix* M){
    this->row_count = M->row_count;
    this->col_count = M->col_count;
    this->entries = new double[this->row_count * this->col_count];

    for (size_t i = 0; i < this->row_count * this->col_count; ++i){
        this->entries[i] = M->entries[i];
    }
}

Matrix::Matrix(size_t rowcol_count) : row_count(rowcol_count), col_count(rowcol_count) {
    this->entries = new double[rowcol_count * rowcol_count];

    std::uniform_real_distribution<double> distribution(-1, 1);

    for (size_t i = 0; i < rowcol_count * rowcol_count; ++i){
        this->entries[i] = distribution(this->generator);
    }
}

Matrix::Matrix(size_t row_count, size_t col_count) : row_count(row_count), col_count(col_count) {

    this->entries = new double[col_count * row_count];

    std::uniform_real_distribution<double> distribution(-1, 1);

    for (size_t i = 0; i < col_count * row_count; ++i){
        this->entries[i] = distribution(this->generator);
    }
}

Matrix::Matrix(size_t row_count, size_t col_count, double init_val) : row_count(row_count), col_count(col_count) {
    this->entries = new double[col_count * row_count];

    for (size_t i = 0; i < col_count * row_count; ++i){
        this->entries[i] = init_val;
    }
}

Matrix::Matrix(size_t row_count, size_t col_count, double* entries) : row_count(row_count), col_count(col_count), entries(entries){}

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

void Matrix::initialize_identity(size_t N){
    delete[] this->entries;
    this->entries = new double[ N * N ];
    for (size_t i = 0; i < N*N; ++i){
        this->entries[i] = 0.0;
    }
    for (size_t i = 0; i < N; ++i){
        this->entries[i * N + i] = 1.0;
    }

    this->row_count = N;
    this->col_count = N;
}

void Matrix::set_entries(double* new_entries){
    delete[] this->entries;
    this->entries = new_entries;
}

double Matrix::evaluate_orthogonality() const {

    size_t N = this->col_count;

    double* QTQ = new double[N * N];
    // Documentation for the method
    // https://icl.bitbucket.io/blaspp/group__gemm.html#details
    cblas_dgemm(CblasRowMajor, CblasTrans, CblasNoTrans, N, N, N, 1.0, this->entries, N, this->entries, N, 0.0, QTQ, N);

    // Subtract the identity
    for (size_t i = 0; i < N * N; i += N + 1) {
        QTQ[i]--;
    }

    // Get max column sums (1-norm)
    double max_sum = 0.0;
    for (size_t i = 0; i < N; i++){
        double current_col_sum = 0.0;

        for (size_t j = 0; j < N; j++) {
            current_col_sum += std::abs(QTQ[j * N + i]);
        }
        if (current_col_sum >= max_sum){
            max_sum = current_col_sum;
        }
    }

    delete[] QTQ;

    return max_sum;
}

void Matrix::transpose(){
    size_t tmp = this->col_count;
    this->col_count = this->row_count;
    this->row_count = tmp;

    double* transposed_entries = new double[this->row_count * this->col_count];

    for (size_t i = 0; i < this->row_count; i++) {
        for (size_t j = 0; j < this->col_count; j++) {
            transposed_entries[j * this->row_count + i] = this->entries[i * this->col_count + j];
        }
    }

    delete[] this->entries;
    this->entries = transposed_entries;
}

void Matrix::subtract_id(){
    size_t min = std::min(this->col_count,this->row_count);
    for (size_t i = 0; i < min; ++i){
        this->entries[i + i * this->col_count]--;
    }
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