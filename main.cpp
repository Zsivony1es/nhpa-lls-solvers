#include <iostream>
#include <cblas.h>
#include <sstream>
#include <vector>
#include <tuple>

#include "include/FileHandler.h"
#include "include/Matrix.h"
#include "include/CGSFactorizer.h"
#include "include/MGSFactorizer.h"

int main() {

    // Get the matrix sizes
    std::vector<std::tuple<size_t, size_t>> matrices_to_factorize{};
    for (size_t m = 100; m <= 5000; m += 100){
        matrices_to_factorize.push_back(std::make_tuple(100, m));
        if (m >= 1000) {
            m += 900;
        }
    }
    for (size_t n = 100; n <= 2900; n += 100){
        matrices_to_factorize.push_back(std::make_tuple(n, 3000));
        if (n >= 1000){
            n += 400;
        }
    }

    std::vector<double> cgs_orth, mgs_orth;

    for (auto& dim : matrices_to_factorize){
        std::cout << "Reading in and constructing [" << get<0>(dim) << "x" << get<1>(dim) << "] matrices..." << std::endl;
        std::stringstream sstream;
        sstream << "./res/matrix_" << get<0>(dim) << "x" << get<1>(dim) << ".txt";
        Matrix* my_matrix = new Matrix(sstream.str());
        Matrix* my_matrix2 = new Matrix(sstream.str());

        CGSFactorizer* cgs = new CGSFactorizer();
        Matrix* Q1 = cgs->factorize(my_matrix);

        MGSFactorizer* mgs = new MGSFactorizer();
        Matrix* Q2 = mgs->factorize(my_matrix2);

        double orth1 = Q1->evaluate_orthogonality();
        cgs_orth.push_back(orth1);
        double orth2 = Q2->evaluate_orthogonality();
        mgs_orth.push_back(orth2);

        std::cout << "1: ||Q^TQ - I||_1 = " << orth1 << std::endl;
        std::cout << "2: ||Q^TQ - I||_1 = " << orth2 << std::endl;
    }

    return 0;
}
