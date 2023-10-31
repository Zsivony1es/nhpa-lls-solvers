#include <iostream>
#include <cblas.h>

#include "include/FileHandler.h"
#include "include/Matrix.h"
#include "include/CGSColumnOrthogonalizer.h"

int main() {

    Matrix* my_matrix = new Matrix("./res/matrix_100x100.txt");

    CGSColumnOrthogonalizer* orthognalizer = new CGSColumnOrthogonalizer();
    orthognalizer->orthogonalize(my_matrix);

    std::cout << "Matrix was orthogonalized, result:" << std::endl;
    std::cout << my_matrix->to_string() << std::endl;

    std::cout << "||Q^TQ - I||_1 = " << my_matrix->evaluate_orthogonality() << std::endl;

    return 0;
}
