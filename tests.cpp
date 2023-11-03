//
// Created by Peter Ivony on 02.11.23.
//

#include <cblas.h>

#include "include/Matrix.h"
#include "include/CGSColumnOrthogonalizer.h"
#include "include/MGSColumnOrthogonalizer.h"
#include "include/HouseholderFactorizer.h"
#include "include/GivensFactorizer.h"

int householder_test(){

    double A[12] = {1, -1, 4, 1, 4, -2, 1, 4, 2, 1, -1, 0};
    Matrix* m1 = new Matrix(4, 3, A);

    HouseholderFactorizer* hf = new HouseholderFactorizer();
    Matrix* Q = hf->factorize(m1);

    double expected_res[12] = {2, 3, 2, 0, 5, -2, 0, 0, 4, 0, 0, 0};
    Matrix* exp = new Matrix(4, 3, expected_res);

    for (size_t i = 0; i < 12; ++i){
        if (expected_res[i] - m1->entries[i] > 1e-15){
            std::cerr << "Householder Orthogonalization was wrong!\nExpected matrix:\n" << exp->to_string() << "\nActual matrix:" << m1->to_string() << std::endl;
            std::cerr << "Q:\n" << Q->to_string() << "\n||Q^TQ - I||_1 = " << Q->evaluate_orthogonality() << std::endl;
            Matrix* QR = new Matrix(4, 3);
            cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, 4, 3, 3, 1.0, Q->entries, 4, m1->entries, 3, 0, QR->entries, 4);
            std::cerr << "QR:\n" << QR->to_string() << std::endl;
            return 1;
        }
    }

    std::cout << "Householder test was successful." << std::endl;
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
            std::cerr <<"\nCGS Orthogonalization was wrong!\nExpected entries:\t\t Actual entries:\n(0.6, 0.8, 0.8, -0.6)\t\t("
                      << m1->entries[0] << ", " << m1->entries[1] << ", " << m1->entries[2] << ", " << m1->entries[3] << ")" << std::endl;
            return 1;
        }
    }

    std::cout << "Classical Gram-Schmidt test was successful." << std::endl;

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
            std::cerr <<"\nMGS Orthogonalization was wrong!\nExpected entries:\t\t Actual entries:\n(0.6, 0.8, 0.8, -0.6)\t\t("
                      << m2->entries[0] << ", " << m2->entries[1] << ", " << m2->entries[2] << ", " << m2->entries[3] << ")" << std::endl;
            return 1;
        }
    }

    std::cout << "Modified Gram-Schmidt test was successful." << std::endl;
    return 0;
}

int givens_rot_test(){
    double entries[9] = {6, 5, 0, 5, 1, 4, 0, 4, 3};
    Matrix* m1 = new Matrix(3, 3, entries);

    GivensFactorizer* givensFactorizer = new GivensFactorizer();
    givensFactorizer->factorize(m1);

    double expected_entries[9] = {7.8102, 4.4813, 2.5607, 0, 4.6817, 0.9665, 0, 0, -4.1843};
    Matrix* expected_matrix = new Matrix(3, 3, expected_entries);

    for (size_t i = 0; i < 12; ++i){
        if (expected_entries[i] - m1->entries[i] > 1e-2){
            std::cerr << "\nGivens rotation was incorrect!\nExpected matrix:\n" << expected_matrix->to_string() << "\nActual matrix:" << m1->to_string() << std::endl;
            return 1;
        }
    }

    std::cout << "Givens rotations test was successful." << std::endl;
    return 0;

}

int main(){

    int errors = 0;

    errors += householder_test();
    errors += cgs_mgs_test();
    errors += givens_rot_test();

    if (errors != 0){
        std::cerr << "\nSome tests have failed!" << std::endl;
        return 1;
    }

    return 0;
}