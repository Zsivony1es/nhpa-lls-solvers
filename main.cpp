#include <iostream>
#include <cblas.h>
#include <sstream>
#include <vector>
#include <tuple>
#include <chrono>

#include "include/FileHandler.h"
#include "include/Matrix.h"
#include "include/CGSFactorizer.h"
#include "include/MGSFactorizer.h"

int main() {

    std::chrono::steady_clock::time_point begin, end;

    // Get the matrix sizes
    std::vector<std::tuple<size_t, size_t>> matrices_to_factorize{};
    size_t count_of_m_is_100 = 0;
    for (size_t m = 100; m <= 5000; m += 100){
        matrices_to_factorize.push_back(std::make_tuple(100, m));
        count_of_m_is_100++;
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
    std::vector<double> cgs_runtimes, mgs_runtimes;

    for (auto& dim : matrices_to_factorize){
        std::cout << "Reading in and constructing [" << get<0>(dim) << "x" << get<1>(dim) << "] matrices..." << std::endl;
        std::stringstream sstream;
        sstream << "./res/matrix_" << get<0>(dim) << "x" << get<1>(dim) << ".txt";
        Matrix* my_matrix = new Matrix(sstream.str());
        Matrix* my_matrix2 = new Matrix(sstream.str());

        CGSFactorizer* cgs = new CGSFactorizer();

        begin = std::chrono::steady_clock::now();
        Matrix* Q1 = cgs->factorize(my_matrix);
        end = std::chrono::steady_clock::now();
        
        cgs_runtimes.push_back(std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() / 1000.0);

        /*
            // Printing QTQ for a certain dimension
            size_t dim1 = 100, dim2 = 200;
            if (get<0>(dim) == dim1 && get<1>(dim) == dim2){
                Matrix* QTQ = new Matrix(100, 100, 0.0);
                cblas_dgemm(CblasRowMajor, CblasTrans, CblasNoTrans, dim1, dim1, dim1, 1.0, Q1->entries, dim1, Q1->entries, dim1, 0.0, QTQ->entries, dim1);
                std::cout << QTQ->to_string() << std::endl;
            }
        */

        MGSFactorizer* mgs = new MGSFactorizer();

        begin = std::chrono::steady_clock::now();
        Matrix* Q2 = mgs->factorize(my_matrix2);
        end = std::chrono::steady_clock::now();
        mgs_runtimes.push_back(std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() / 1000.0);

        double orth1 = Q1->evaluate_orthogonality();
        cgs_orth.push_back(orth1);
        double orth2 = Q2->evaluate_orthogonality();
        mgs_orth.push_back(orth2);

        std::cout << "CGS: ||Q^TQ - I||_1 = " << orth1 << "\tRuntime:" << cgs_runtimes.back() << "s" << std::endl;
        std::cout << "MGS: ||Q^TQ - I||_1 = " << orth2 << "\tRuntime:" << mgs_runtimes.back() << "s" << std::endl;
    }

    // Write files for plots
    std::stringstream out_str;

    out_str << "100x___: ";
    for (size_t m = 100; m <= 5000; m += 100){
        out_str << m;
        if (m != 5000){
            out_str << ", ";
        }
        if (m >= 1000) {
            m += 900;
        }
    }

    out_str << "\nCGS-orthogonality: ";
    for (int i = 0; i < count_of_m_is_100; ++i){
        out_str << cgs_orth[i];
        if (i + 1 != count_of_m_is_100){
            out_str << ", ";
        }
    }
    out_str << "\nCGS-runtime: ";
    for (int i = 0; i < count_of_m_is_100; ++i){
        out_str << cgs_runtimes[i];
        if (i + 1 != count_of_m_is_100){
            out_str << ", ";
        }
    }
    out_str << "\nMGS-orthogonality: ";
    for (int i = 0; i < count_of_m_is_100; ++i){
        out_str << mgs_orth[i];
        if (i + 1 != count_of_m_is_100){
            out_str << ", ";
        }
    }
    out_str << "\nMGS-runtime: ";
    for (int i = 0; i < count_of_m_is_100; ++i){
        out_str << mgs_runtimes[i];
        if (i + 1 != count_of_m_is_100){
            out_str << ", ";
        }
    }

    out_str << "\n\n___x3000: ";
    for (size_t n = 100; n <= 2900; n += 100){
        out_str << n;
        if (n != 2500){
            out_str << ", ";
        }
        if (n >= 1000){
            n += 400;
        }
    }

    out_str << "\nCGS-orthogonality: ";
    for (int i = count_of_m_is_100; i < matrices_to_factorize.size(); ++i){
        out_str << cgs_orth[i];
        if (i + 1 != matrices_to_factorize.size()){
            out_str << ", ";
        }
    }
    out_str << "\nCGS-runtimes: ";
    for (int i = count_of_m_is_100; i < matrices_to_factorize.size(); ++i){
        out_str << cgs_runtimes[i];
        if (i + 1 != matrices_to_factorize.size()){
            out_str << ", ";
        }
    }
    out_str << "\nMGS-runtimes: ";
    for (int i = count_of_m_is_100; i < matrices_to_factorize.size(); ++i){
        out_str << mgs_runtimes[i];
        if (i + 1 != matrices_to_factorize.size()){
            out_str << ", ";
        }
    }

    FileHandler::writeFile("./out/results.txt", out_str.str());

    return 0;
}
