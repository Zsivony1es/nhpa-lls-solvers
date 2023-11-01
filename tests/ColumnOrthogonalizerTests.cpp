//
// Created by Peter Ivony on 01.11.23.
//

#include <cblas.h>

#include "../include/Matrix.h"
#include "../include/CGSColumnOrthogonalizer.h"
#include "../include/MGSColumnOrthogonalizer.h"

int main(){

    Matrix* my_matrix = new Matrix(2, 2);
    my_matrix->entries[0] = 3;
    my_matrix->entries[1] = 4;
    my_matrix->entries[2] = 4;
    my_matrix->entries[3] = 4;

    CGSColumnOrthogonalizer* cgs = new CGSColumnOrthogonalizer();
    cgs->orthogonalize(my_matrix);


    double expected[4] = {0.6, 0.8, 0.8, -0.6};

    for (size_t i = 0; i < 4; ++i){
        if (expected[i] - my_matrix->entries[i] > 0.00001){
            std::cout <<"Orthogonalization was wrong!\nExpected entries:\t\t Actual entries:\n(0.6, 0.8, 0.8, -0.6)\t\t("
                    << my_matrix->entries[0] << ", " << my_matrix->entries[1] << ", " << my_matrix->entries[2] << ", " << my_matrix->entries[3] << ")" << std::endl;
            return 1;
        }
    }

    return 0;
}