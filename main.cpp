#include <iostream>
#include <cblas.h>

#include "include/FileHandler.h"
#include "include/Matrix.h"

int main() {
    // Define the matrix A and vector x
    double A[] = {1.0, 2.0, 3.0, 4.0}; // 2x2 matrix
    double x[] = {5.0, 6.0};          // 2-dimensional vector

    size_t col = 10, row = 10;
    Matrix* my_matrix = new Matrix(col, row);

    std::cout << my_matrix->to_string() << std::endl;

    // Create a vector to store the result
    double b[2];

    // Perform a matrix-vector multiplication using cblas
    cblas_dgemv(CblasRowMajor, CblasNoTrans, 2, 2, 1.0, A, 2, x, 1, 0.0, b, 1);

    // Print the result
    std::cout << "Matrix A:" << std::endl;
    std::cout << "1.0 2.0" << std::endl;
    std::cout << "3.0 4.0" << std::endl;

    std::cout << "Vector x:" << std::endl;
    std::cout << "5.0" << std::endl;
    std::cout << "6.0" << std::endl;

    std::cout << "Result b = A * x:" << std::endl;
    std::cout << b[0] << std::endl;
    std::cout << b[1] << std::endl;

    std::string my_str = "hello";
    std::string matrix_path = "./res/out.txt";

    FileHandler::writeFile(matrix_path, my_str);


    return 0;
}
