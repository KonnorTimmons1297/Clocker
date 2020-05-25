#include <filesystem>
#include <fstream>

#include "clocker.h"
#include "json.hpp"

using std::fstream;
using json = nlohmann::json;

namespace fs = std::filesystem;

static const char *CONFIG_DIR = "/home/konnor/.clocker";
static const char *CONFIG_FILE_NAME = "config";

static const char *KEY_LAST_USER = "LAST_USER";

ClockerConfig::ClockerConfig() : Config(CONFIG_DIR, CONFIG_FILE_NAME) {
    string config_file_path;
    config_file_path = (string) CONFIG_DIR + fs::path::preferred_separator + (string) CONFIG_FILE_NAME;

    fstream config_file(config_file_path, std::ios::in);

    //Getting file size
    config_file.seekg(0, std::ios::end);
    auto file_size = config_file.tellg();

    if (file_size > 0) {
        char *config_data = new char[file_size];
        config_file.read(config_data, file_size);
        deserialize(config_data);

        delete[] config_data;
    } else {
        first_open = true;
    }

    config_file.close();
}

void ClockerConfig::deserialize(const string &config_data) {
    auto j = json::parse(config_data);

    last_user = j[KEY_LAST_USER];
}

string ClockerConfig::serialize() {
    json obj;

    obj[KEY_LAST_USER] = last_user;

    return obj.dump();
}

bool ClockerConfig::save() {
    string config_file_path;
    config_file_path = (string) CONFIG_DIR + fs::path::preferred_separator + (string) CONFIG_FILE_NAME;

    fstream config_file(config_file_path, std::ios::out);

    if (config_file.good()) {
        config_file << serialize();
    } else {
        return false;
    }

    config_file.flush();
    config_file.close();

    return true;
}
