#ifndef FILE_UTIL_H
#define FILE_UTIL_H

#include <filesystem>
#include <iostream>
#include <fstream>
#include <string>

#include "logger.h"

using std::ifstream;
using std::ios;
using std::string;

namespace fs = std::filesystem;

namespace file_util {

    bool exists(string file_path) {
        return fs::exists(file_path);
    }

    string read(string file_path) {
        ifstream file(file_path, ios::in);

        if (file.bad()) {
            std::cout << "Unable to open file: " << file_path << std::endl;
            exit(-1);
        }

        file.open(file_path);

        //Retrieving the size of the file
        file.seekg(0, ios::end);
        auto file_size = file.tellg();

        if (file_size < 0) {
            return "";
        }

        char *file_data = new char[file_size];

        file.read(file_data, file_size);

        file.close();

        return file_data;
    }

    bool create(string file_path) {
        bool result;

        result = fs::create_directory(file_path);


        return result;
    }

}

#endif
