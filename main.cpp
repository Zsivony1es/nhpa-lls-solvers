#include <iostream>
#include <cblas.h>

#include "include/FileHandler.h"
#include "include/Matrix.h"
#include "include/CGSFactorizer.h"
#include "include/MGSFactorizer.h"

int main() {

    std::cout << "Reading in and constructing matrices..." << std::endl;

    Matrix* my_matrix = new Matrix("./res/matrix_2500x3000.txt");
    Matrix* my_matrix2 = new Matrix("./res/matrix_2500x3000.txt");

    CGSColumnOrthogonalizer* cgs = new CGSColumnOrthogonalizer();
    cgs->orthogonalize(my_matrix);

    std::cout << "Matrix 1 was orthogonalized" << std::endl;

    MGSColumnOrthogonalizer* mgs = new MGSColumnOrthogonalizer();
    mgs->orthogonalize(my_matrix2);

    std::cout << "Matrix 2 was orthogonalized" << std::endl;

    std::cout << "Evaluating orthogonality metrics..." << std::endl;

    double orth1 = my_matrix->evaluate_orthogonality();
    double orth2 = my_matrix2->evaluate_orthogonality();

    std::cout << "1: ||Q^TQ - I||_1 = " << orth1 << std::endl;
    std::cout << "2: ||Q^TQ - I||_1 = " << orth2 << std::endl;

    return 0;
}
