//
// Created by Peter Ivony on 31.10.23.
//

#ifndef HOMEWORK1_FILEHANDLER_H
#define HOMEWORK1_FILEHANDLER_H

#include <iostream>

class FileHandler{

public:
    static bool writeFile(const std::string& filename, const std::string& content);
    static bool readFile(const std::string& filename, std::string& content);
};

#endif //HOMEWORK1_FILEHANDLER_H
