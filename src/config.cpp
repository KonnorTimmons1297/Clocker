#include <iostream>
#include <fstream>
#include <filesystem>

#include "config.h"

#include "json.hpp"

using std::fstream;

namespace fs = std::filesystem;

Config::Config(const string &config_dir, const string &file_name) {
    if (config_dir.length() == 0) {
        std::cout << "Config::Config() => config_dir is empty" << std::endl;
        exit(1);
    }

    if (file_name.length() == 0) {
        std::cout << "Config::Config() => file_name is empty" << std::endl;
        exit(1);
    }

    this->config_dir = config_dir;
    this->file_name = file_name;

    fs::directory_entry config_directory(config_dir);

    if (!config_directory.exists()) {
        fs::create_directory(config_dir);
    }

    string full_config_file_path;
    full_config_file_path = config_dir + fs::path::preferred_separator + file_name;

    fstream config_file(full_config_file_path, std::ios::in);

    config_file << " ";

    config_file.flush();
    config_file.close();
}

bool Config::save() {
    if (config_dir.length() == 0) {
        std::cout << "Config::save() => config_dir is empty" << std::endl;
        return false;
    }

    if (file_name.length() == 0) {
        std::cout << "Config::save() => file_name is empty" << std::endl;
        return false;
    }

    return true;
}
