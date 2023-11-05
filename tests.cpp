//
// Created by Peter Ivony on 02.11.23.
//

#include <cblas.h>
#include <math.h>

#include "include/Matrix.h"
#include "include/CGSFactorizer.h"
#include "include/MGSFactorizer.h"
#include "include/HouseholderFactorizer.h"
#include "include/GivensFactorizer.h"

int householder_test(){

    double A[9] = {1, 3, 5, 1, 3, 1, 2, -1, 7};
    Matrix* m1 = new Matrix(3, 3, A);

    HouseholderFactorizer* hf = new HouseholderFactorizer();
    Matrix* Q = hf->factorize(m1);

    double expected_res[9] = {sqrt(6), 2 * sqrt(6)/3, 10 * sqrt(6)/3, 0, 7*sqrt(3)/3, -sqrt(3)/3, 0, 0, 2 * sqrt(2)};
    Matrix* exp = new Matrix(3, 3, expected_res);

    for (size_t i = 0; i < exp->row_count * exp->col_count; ++i){
        if (expected_res[i] - m1->entries[i] > 1e-15){
            std::cerr << "Householder Orthogonalization was wrong!\nExpected matrix:\n" << exp->to_string() << "\nActual matrix:" << m1->to_string() << std::endl;
            std::cerr << "Q:\n" << Q->to_string() << "\n||Q^TQ - I||_1 = " << Q->evaluate_orthogonality() << std::endl;

            return 1;
        }
    }

    std::cout << "Householder test was successful." << std::endl;
    return 0;
}

int cgs_mgs_test(){

    // CGS TEST
    CGSFactorizer* cgs = new CGSFactorizer();
    Matrix* R1 = new Matrix(2, 2);
    R1->entries[0] = 3;
    R1->entries[1] = 4;
    R1->entries[2] = 4;
    R1->entries[3] = 4;

    Matrix* Q1 = cgs->factorize(R1);

    double e1[4] = {0.6, 0.8, 0.8, -0.6};

    for (size_t i = 0; i < 4; ++i){
        if (e1[i] - Q1->entries[i] > 1e-15){
            std::cerr <<"\nCGS Orthogonalization was wrong!\nExpected entries:\t\t Actual entries:\n(0.6, 0.8, 0.8, -0.6)\t\t("
                      << Q1->entries[0] << ", " << Q1->entries[1] << ", " << Q1->entries[2] << ", " << Q1->entries[3] << ")" << std::endl;
            return 1;
        }
    }

    std::cout << "Classical Gram-Schmidt test was successful." << std::endl;

    // MGS TEST
    MGSFactorizer* mgs = new MGSFactorizer();
    Matrix* R2 = new Matrix(2, 2);
    R2->entries[0] = 3;
    R2->entries[1] = 4;
    R2->entries[2] = 4;
    R2->entries[3] = 4;

    Matrix* Q2 = mgs->factorize(R2);

    double e2[4] = {0.6, 0.8, 0.8, -0.6};

    for (size_t i = 0; i < 4; ++i){
        if (e2[i] - Q2->entries[i] > 1e-15){
            std::cerr <<"\nMGS Orthogonalization was wrong!\nExpected entries:\t\t Actual entries:\n(0.6, 0.8, 0.8, -0.6)\t\t("
                      << Q2->entries[0] << ", " << Q2->entries[1] << ", " << Q2->entries[2] << ", " << Q2->entries[3] << ")" << std::endl;
            return 1;
        }
    }

    std::cout << "Modified Gram-Schmidt test was successful." << std::endl;
    return 0;
}

int givens_rot_test(){
    double A[9] = {1, 3, 5, 1, 3, 1, 2, -1, 7};
    Matrix* m1 = new Matrix(3, 3, A);

    GivensFactorizer* gf = new GivensFactorizer();
    Matrix* Q = gf->factorize(m1);

    double expected_res[9] = {sqrt(6), 2 * sqrt(6)/3, 10 * sqrt(6)/3, 0, 7*sqrt(3)/3, -sqrt(3)/3, 0, 0, 2 * sqrt(2)};
    Matrix* exp = new Matrix(3, 3, expected_res);

    for (size_t i = 0; i < exp->col_count * exp->row_count; ++i){
        if (expected_res[i] - m1->entries[i] > 1e-4){
            std::cerr << "\nGivens rotation was incorrect!\nExpected matrix:\n" << exp->to_string() << "\nActual matrix:" << m1->to_string() << std::endl;
            return 1;
        }
    }

    std::cout << "Givens rotations test was successful." << std::endl;
    return 0;

}

int main(){

    int errors = 0;

    // errors += householder_test();
    errors += cgs_mgs_test();
    // errors += givens_rot_test();

    if (errors != 0){
        std::cerr << "\nSome tests have failed!" << std::endl;
        return 1;
    }

    return 0;
}