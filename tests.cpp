//
// Created by Peter Ivony on 02.11.23.
//

#include <cblas.h>

#include "include/Matrix.h"
#include "include/CGSColumnOrthogonalizer.h"
#include "include/MGSColumnOrthogonalizer.h"
#include "include/HouseholderFactorizer.h"

int householder_test(){

    double A[12] = {1, -1, 4, 1, 4, -2, 1, 4, 2, 1, -1, 0};
    Matrix* m1 = new Matrix(4, 3, A);

    HouseholderFactorizer* hf = new HouseholderFactorizer();
    hf->factorize(m1);

    double expected_res[12] = {2, 3, 2, 0, 5, -2, 0, 0, 4, 0, 0, 0};
    Matrix* exp = new Matrix(4,3,expected_res);

    for (size_t i = 0; i < 12; ++i){
        if (expected_res[i] - m1->entries[i] > 1e-15){
            std::cout << "Orthogonalization was wrong!\nExpected matrix:\n" << exp->to_string() << "\nActual matrix:" << m1->to_string() << std::endl;
            return 1;
        }
    }

    return 0;
}

int cgs_mgs_test(){

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

int main(){

    int errors = 0;

    errors += householder_test();
    errors += cgs_mgs_test();

    if (errors != 0){
        std::cout << "Some tests have failed!" << std::endl;
        return 1;
    }

    return 0;
}