//
// Created by Peter Ivony on 31.10.23.
//

#include "include/FileHandler.h"
#include "include/Matrix.h"

#include <vector>
#include <sstream>

using namespace std;

int main(){

    vector<tuple<size_t, size_t>> matrices_to_generate{};
    for (size_t m = 100; m <= 5000; m += 100){
        matrices_to_generate.push_back(make_tuple(100, m));
        if (m >= 1000) {
            m += 900;
        }
    }
    for (size_t n = 100; n <= 2900; n += 100){
        matrices_to_generate.push_back(make_tuple(n, 3000));
        if (n >= 1000){
            n += 400;
        }
    }

    for (auto &dim : matrices_to_generate){
        stringstream ss;
        ss << "res/matrix_" << get<0>(dim) << "x" << get<1>(dim) << ".txt";

        Matrix* matrix = new Matrix(get<0>(dim), get<1>(dim));
        cout << "Generating file: " << ss.str() << std::endl;
        FileHandler::writeFile(ss.str(), matrix->to_string());
    }

}