#include <iostream>
#include <cblas.h>

#include "include/FileHandler.h"
#include "include/Matrix.h"
#include "include/CGSColumnOrthogonalizer.h"

int main() {

    Matrix* my_matrix = new Matrix("./res/matrix_100x100.txt");

    std::cout << my_matrix->to_string() << std::endl;

    CGSColumnOrthogonalizer* orthognalizer = new CGSColumnOrthogonalizer();
    orthognalizer->orthogonalize(my_matrix);

    std::cout << my_matrix->to_string() << std::endl;

    return 0;
}
