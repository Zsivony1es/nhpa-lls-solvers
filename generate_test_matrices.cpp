//
// Created by Peter Ivony on 31.10.23.
//

#include "include/FileHandler.h"

int main(){

    std::string& my_str = "hello";
    std::string& matrix_path = "res/out.txt";

    FileHandler::writeFile(matrix_path, my_str);

}