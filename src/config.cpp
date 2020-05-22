#include "config.h"

#include "json.hpp"
#include "util.h"

using json = nlohmann::json;

string Config::serialize() {
    json config_json;

    config_json[""] = last_user;

    return config_json.dump();
}

Config Config::deserialize(string config_json) {
    auto json = json::parse(config_json);
    Config test;
    return test;
}

bool Config::create(string file_name) {
    return false;
}

bool Config::read(string file_name) {
    if(file_name.length() == 0) return false;
    
    char *file_data = util::readFile(file_name.c_str());
    string config_json(file_data);
    Config config = deserialize(config_json);

    return true;
}

bool Config::write(string file_name) {
    return true;
}
