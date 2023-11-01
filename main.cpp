#include <iostream>
#include <cblas.h>

#include "include/FileHandler.h"
#include "include/Matrix.h"
#include "include/CGSColumnOrthogonalizer.h"

int main() {

    Matrix* my_matrix = new Matrix("./res/matrix_100x400.txt");

    CGSColumnOrthogonalizer* orthognalizer = new CGSColumnOrthogonalizer();
    orthognalizer->orthogonalize(my_matrix);

    std::cout << "Matrix was orthogonalized, result:" << std::endl;
    std::cout << my_matrix->to_string() << std::endl;

    double orthogonality = my_matrix->evaluate_orthogonality();

    std::cout << "||Q^TQ - I||_1 = " << orthogonality << std::endl;

    return 0;
}
