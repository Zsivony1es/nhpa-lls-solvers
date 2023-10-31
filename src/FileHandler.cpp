//
// Created by Peter Ivony on 31.10.23.
//

#include "FileHandler.h"

#include <fstream>

bool FileHandler::writeFile(const std::string& filename, const std::string& content) {
    std::ofstream file(filename);

    if (file.is_open()) {
        file << content;
        file.close();
        return true;
    } else {
        std::cerr << "Unable to open file for writing: " << filename << std::endl;
        return false;
    }
}

bool FileHandler::readFile(const std::string& filename, std::string& content) {
    std::ifstream file(filename);

    if (file.is_open()) {
        std::string line;
        content = "";
        while (std::getline(file, line)) {
            content += line + "\n";
        }

        file.close();
        return true;
    } else {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return false;
    }
}