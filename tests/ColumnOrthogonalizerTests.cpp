//
// Created by Peter Ivony on 01.11.23.
//

#include <cblas.h>

#include "../include/Matrix.h"
#include "../include/CGSColumnOrthogonalizer.h"
#include "../include/MGSColumnOrthogonalizer.h"

int main(){

    // CGS TEST
    CGSColumnOrthogonalizer* cgs = new CGSColumnOrthogonalizer();
    Matrix* m1 = new Matrix(2, 2);
    m1->entries[0] = 3;
    m1->entries[1] = 4;
    m1->entries[2] = 4;
    m1->entries[3] = 4;

    cgs->orthogonalize(m1);

    double e1[4] = {0.6, 0.8, 0.8, -0.6};

    for (size_t i = 0; i < 4; ++i){
        if (e1[i] - m1->entries[i] > 1e-15){
            std::cout <<"Orthogonalization was wrong!\nExpected entries:\t\t Actual entries:\n(0.6, 0.8, 0.8, -0.6)\t\t("
                      << m1->entries[0] << ", " << m1->entries[1] << ", " << m1->entries[2] << ", " << m1->entries[3] << ")" << std::endl;
            return 1;
        }
    }

    // MGS TEST
    MGSColumnOrthogonalizer* mgs = new MGSColumnOrthogonalizer();
    Matrix* m2 = new Matrix(2, 2);
    m2->entries[0] = 3;
    m2->entries[1] = 4;
    m2->entries[2] = 4;
    m2->entries[3] = 4;

    mgs->orthogonalize(m2);

    double e2[4] = {0.6, 0.8, 0.8, -0.6};

    for (size_t i = 0; i < 4; ++i){
        if (e2[i] - m2->entries[i] > 1e-15){
            std::cout <<"Orthogonalization was wrong!\nExpected entries:\t\t Actual entries:\n(0.6, 0.8, 0.8, -0.6)\t\t("
                      << m2->entries[0] << ", " << m2->entries[1] << ", " << m2->entries[2] << ", " << m2->entries[3] << ")" << std::endl;
            return 1;
        }
    }

    return 0;
}