#include <iostream>
#include <fstream>
#include <string>

using std::ifstream;
using std::ios;
using std::string;

namespace file_util
{
    bool exists(const char *file_path)
    {
        ifstream file(file_path);
        return file.good();
    }

    string read(const char *file_path)
    {
        ifstream file(file_path, ios::in);

        if (file.bad())
        {
            std::cout << "Unable to open file: " << file_path << std::endl;
            exit(-1);
        }

        file.open(file_path);

        //Retrieving the size of the file
        file.seekg(0, ios::end);
        auto file_size = file.tellg();

        char *file_data = new char[file_size];

        file.read(file_data, file_size);

        file.close();

        return file_data;
    }
} // namespace file_util
